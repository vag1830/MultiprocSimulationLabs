/* Algoritmo de Jacobi */

#include <rsim_apps.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef volatile int Lock;
typedef int boolean;
#define FALSE 0
#define TRUE (!FALSE)

typedef struct
{
    int next_pid;
    double diff;
    boolean done;
    Lock lock;
    TreeBar barrier;
} GlobalMemory;

static GlobalMemory *global;

static int n = 16;
static double tolerance = 0.1;
static double **A;
static double **B;
static int cpb = 2;               /* cols per processor: 1, 2, 4, 8 ó 16 */
static int number_of_processes = 4;
static boolean verbose = FALSE;

static int num_iterations = 0;

typedef struct
{
    double T0;
    double T1;
    double T2;
    double T3;
    double T4;
} InitialSetup;

static void
show (void)
{
    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = 0; j < n + 2; ++j)
        {
            printf ("%6.1f", A[i][j]);
        }
	printf ("\n");
    }
}

static void
solve (void)
{
    int pid;

    GETLOCK (&global->lock);
    {
        pid = global->next_pid;
        global->next_pid++;
    }
    FREELOCK (&global->lock);

    int cols_per_thr = (n + number_of_processes - 1) / number_of_processes;
    int first_col = pid * cols_per_thr + 1;
    int last_col = MIN ((pid + 1) * cols_per_thr, n);

    do
    {
	++num_iterations;
        double mydiff = 0.0f;

        if (pid == 0)
        {
	    GETLOCK (&global->lock);
	    {
		global->diff = 0;
	    }
	    FREELOCK (&global->lock);
        }

        TREEBAR (&global->barrier, pid);

	if (global->done)
	{
	    break;
	}

        for (int col = first_col; col <= last_col; col += cpb)
        {
            for (int row = 1; row <= n; ++row)
            {
                for (int j = 0; j < cpb; ++j)
                {
                    B[row][col + j] =
                      0.2 * (A[row][col + j] + A[row + 1][col + j] + A[row][col + j + 1] + A[row - 1][col + j] +
                             A[row][col + j - 1]);
                    mydiff += fabs (B[row][col + j] - A[row][col + j]);
                }
            }
        }

        GETLOCK (&global->lock);
        {
            global->diff += mydiff;
        }
        FREELOCK (&global->lock);

        TREEBAR (&global->barrier, pid);

        double **temp = A;
        A = B;
        B = temp;

        if (verbose && pid == 0)
        {
            printf ("diff = %f\n", global->diff / (n * n));
	    /* show (); */
            fflush (stdout);
        }

        if (global->diff / (n * n) < tolerance)
        {
            global->done = TRUE;
        }
        TREEBAR (&global->barrier, pid);
    }
    while (TRUE);
}

static void
initialize (InitialSetup *setup)
{
    global = (GlobalMemory *) shmalloc (sizeof (GlobalMemory));

    A = (double **) calloc (n + 2, sizeof (double *));
    for (int i = 0; i <= n + 1; i++)
    {
        A[i] = (double *) shmalloc ((n + 2) * sizeof (double));
        AssociateAddrNode (A[i], A[i] + (sizeof (double) * (n + 2)) - 1, 0, "A");
    }

    B = (double **) calloc (n + 2, sizeof (double *));
    for (int i = 0; i <= n + 1; i++)
    {
        B[i] = (double *) shmalloc ((n + 2) * sizeof (double));
        AssociateAddrNode (B[i], B[i] + (sizeof (double) * (n + 2)) - 1, 0, "B");
    }

    global->next_pid = 0;
    TreeBarInit (&global->barrier, number_of_processes);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            A[i][j] = setup->T4;
        }
    }

    for (int j = 1; j <= n; ++j)
    {
	A[0][j] = setup->T0;
	A[n + 1][j] = setup->T2;
	B[0][j] = setup->T0;
	B[n + 1][j] = setup->T2;
    }
    
    for (int i = 0; i <= n + 1; ++i)
    {
	A[i][0] = setup->T1;
	A[i][n + 1] = setup->T3;
	B[i][0] = setup->T1;
	B[i][n + 1] = setup->T3;
    }
}

int
main (int argc, char *argv[])
{
    if (argc > 1)
    {
        n = atoi (argv[1]);
    }

    if (argc > 2)
    {
        number_of_processes = atoi (argv[2]);
    }

    if (argc > 3)
    {
        tolerance = atof (argv[3]);
    }

    if (argc > 4)
    {
        cpb = atoi (argv[4]);
    }

    if (cpb > n)
    {
        fprintf (stderr, "Columns per block demasiado grande.\n");
        return 1;
    }

    if ((n % cpb) != 0)
    {
        fprintf (stderr, "Columns per block no divide al tamaño.\n");
        return 1;
    }

    if (argc > 5)
    {
        verbose = atoi (argv[5]);
    }

    InitialSetup setup;
    setup.T0 = 150;
    setup.T1 = 70;
    setup.T2 = 150;
    setup.T3 = 70;
    setup.T4 = 10;

    printf ("n = %d, number_of_processes = %d, tolerance = %f, cpb = %d\n", n, number_of_processes, tolerance, cpb);

    initialize (&setup);
    if (verbose)
    {
	printf ("Initial state:\n");
	show ();
    }

    for (int i = 1; i < number_of_processes; i++)
    {
        if (!fork ())
        {
            solve ();
            return 0;
        }
    }
    solve ();

    printf ("%d iterations.\n", num_iterations);
    if (verbose)
    {
	printf ("Final state:\n");
	show ();
    }

    return 0;
}
