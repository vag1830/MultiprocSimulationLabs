/*
      Multiplicacion de un array por una constante en paralelo 
*/ 

#include <rsim_apps.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ABS(x) ((x) < (0) ? -(x) : (x))

int numProcs = 1;

TreeBar inicia; 
double *o_array;
int o_array_size = 256;

void 
SlaveStart(int my_id);

static unsigned long long int l[10];
static double d[10] = { 0.0, 0.5, 1.0, 1.5, 2.0, -0.5, -1.0, -1.5, -2.0, 3.14159265359 };
static float f[10] = { 0.0f, 0.5f, 1.0f, 1.5f, 2.0f, -0.5f, -1.0f, -1.5f, -2.0f, 3.14159265359f };

static void
show_array (void)
{
  int i;
  for (i = 0; i < o_array_size; ++i)
    {
      printf ("%5d ", (int) o_array[i]);
    }
  printf ("\n");
}

int 
main (int argc, char **argv) 
{
    int i;
    int proc_id = 0;

    printf ("%d\n", argc);
    for (i = 0; i < argc; ++i)
    {
    	printf ("%s\n", argv[i]);
    }

    {
       printf ("");
       off_t o = lseek (1, 0, SEEK_CUR);
       printf ("%d\n", o);
    }

    printf ("l %x %d\n", (unsigned int) l, sizeof (l));
    printf ("d %x %d\n", (unsigned int) d, sizeof (d));
    printf ("f %x %d\n", (unsigned int) f, sizeof (f));

    if (argc > 1)
      {
	numProcs = atoi (argv [1]);
      }

    if (argc > 2)
      {
	o_array_size = atoi (argv [1]);
      }

    TreeBarInit (&inicia, numProcs); 

    for (i = 0; i < 10; ++i)
    {
    	l[i] = i + 1;
    }

    for (i = 0; i < 10; ++i)
    {
	long long int x = l[i];
        printf ("XX%lldXX ", x);
	x = x * (x << 20) + x;
	l[i] = x;    	
        printf ("XX%lldXX\n", x);
    }

    for (i = 1; i < 10; ++i)
    {
	long long int x = l[i];
        printf ("XX%lldXX ", x);
	x = x * (l[i - 1] + 1);
	l[i] = x;    	
        printf ("XX%lldXX\n", x);
    }

    for (i = 0; i < 10; ++i)
    {
    	printf ("%f\n", d[i]);
    	double x = d[i];
   	printf ("%f\n", x);
      	x = x + 1.0;
   	printf ("%f\n", x);
    	d[i] = x;
    	printf ("%f\n", d[i]);
    }

    for (i = 0; i < 10; ++i)
    {
    	float x = f[i];
    	x = x + 1.0f;
    	f[i] = x;
    	printf ("%f\n", f[i]);
    }

    if (!(ABS (d[3] - 2.5) < 0.001))
    {
    	printf ("ERROR 1: %f\n", d[3]);
    	return 1;
    }
    
    if (!(ABS (f[3] - 2.5f) < 0.001))
    {
    	printf ("ERROR 2 %f\n", f[3]);
    	return 2;
    }

    l[3] = 1;
    l[3] = l[3] << 37;

    printf ("XX%fXX\n", d[3]);
    printf ("XX%fXX\n", f[3]);
    printf ("XX%lldXX\n", l[3]);

    o_array = (double *) shmalloc (o_array_size * sizeof (double));
    AssociateAddrNode (o_array, o_array + o_array_size - 1, 0, "nada");

    printf ("%x %d\n", (unsigned int) o_array, o_array_size * sizeof (double));

    /* Initiate the original array */
    for (i=0; i < o_array_size; i++) 
      {
	o_array[i] = i;
      }
    printf("Original array initiated!!\n");

    show_array ();

    if (!getpid()) StatClearAll();
    /* Create the slave processes. */

    for (i = 1; i < numProcs; i++)
      {
        if (fork() == 0) {
	  proc_id = getpid();
	  printf("Just another one (%d/%d): %d\n", i, numProcs, proc_id);
	  fflush (stdout);
	  break;
        }
      }
    
    if (!proc_id) 
      {
	printf("Slaves created!!\n");
	fflush (stdout);
      }

MEMSYS_OFF;
    TREEBAR(&inicia,proc_id);
MEMSYS_ON;
    SlaveStart(proc_id);
MEMSYS_OFF;
    TREEBAR(&inicia,proc_id);
MEMSYS_ON;

    if (proc_id == 0) 
      {
	StatReportAll();
	
	printf ("Result:\n");
	show_array ();
      }
}

/* This is the routine that each processor will be executing in parallel */
 
void
SlaveStart (int my_id) 
{
  int i;
  int inicio = my_id * (o_array_size / numProcs);
  int fin;
  if (my_id == numProcs - 1)
    {
      fin = o_array_size;
    }
  else
    {
      fin = inicio + (o_array_size / numProcs);
    }
  
  for (i = inicio; i < fin; ++i) 
    {
      o_array[i] *= 3;
    }
}

