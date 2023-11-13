#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define NUM 4

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y)
{

/*   #pragma omp parallel
   {
      int nthreads = omp_get_num_threads();
      int thread_id = omp_get_thread_num();
      printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
      printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
   }*/

		#pragma omp parallel for
		for(int row = 0; row < n; row++)
		{
			double sum = 0;

			for(int col = 0; col < n; col++)
			{
				sum += A[row * n +col] * x[col];
			}
				y[row] += sum;
		}


   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings

}

