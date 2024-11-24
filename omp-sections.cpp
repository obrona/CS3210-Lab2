#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
Simple example of openmp sections and why we need them
*/
int main(int argc, char* argv[])
{
    
    #pragma omp parallel 
    {
        // Try adding a "nowait" after "sections" 
        // no wait means after a fork, there is no implicit barrier
        /*#pragma omp sections
        {
            #pragma omp section 
            {
                printf("1. Hello World from thread = %d\n", omp_get_thread_num());
            }
            
            #pragma omp section 
            {
                printf("2. Hello World from thread = %d\n", omp_get_thread_num());
            }
            
            #pragma omp section 
            {
                printf("3. Hello World from thread = %d\n", omp_get_thread_num());
            }
            
            #pragma omp section 
            {
                printf("4. Hello World from thread = %d\n", omp_get_thread_num());
            }
        }*/

        #pragma omp for`
        for (int i = 0; i < 12; i ++) {
            printf("%d. Hello World from thread = %d\n", i, omp_get_thread_num());
        }

        #pragma omp master
        printf("Master thread printing - thread = %d\n", omp_get_thread_num());

        #pragma omp single
        printf("Single thread printing - thread = %d\n", omp_get_thread_num());

        
    }

   

        


}
