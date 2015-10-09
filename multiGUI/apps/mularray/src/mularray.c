/*
      Multiplicacion de un array por una constante en paralelo 
*/ 

#include <rsim_apps.h>
#include <stdio.h>
#include <stdlib.h>

int numProcs = 10;

typedef int num;

TreeBar inicia; 
num *o_array;
int o_array_size = 512;

void 
SlaveStart(int my_id);

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

    if (argc > 1)
      {
	numProcs = atoi (argv [1]);
      }

    if (argc > 2)
      {
	o_array_size = atoi (argv [2]);
      }

    TreeBarInit (&inicia, numProcs); 

    o_array = (num *) shmalloc (o_array_size * sizeof (num));
    AssociateAddrNode (o_array, o_array + o_array_size - 1, 0, "nada");

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

