#include "wavelet.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void parallel_cwt_1d(int nb_thrd){
	printf("*************** PARALLEL VERSION WAVELET TRANSFORM ******************\n");
	nb_thread = nb_thrd;

	global_coefs = new_matrice(global_scales.size, global_signal.size) ; 

	pthread_mutex_init(&mutexsum, NULL);
	pthread_t* callThd = (pthread_t*)malloc(nb_thread*sizeof(pthread_t));
	pthread_attr_t attr;
	void* status;

	/* Create threads to perform training */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for(int i=0; i<nb_thread; i++)
	{
		/* Each thread works on a different set of data. The offset is specified by 'i'. The size of the data for each thread is computed. */
		pthread_create(&callThd[i], &attr, thread_cwt, (void *)i);
	}
	pthread_attr_destroy(&attr);

	/* Wait on the other threads */
	for(int i=0; i<nb_thread; i++)
	{
		pthread_join(callThd[i], &status);
	}
	
	/* After joining cleanup */

	pthread_mutex_destroy(&mutexsum);
	//pthread_exit(NULL);
}

void* thread_cwt( void* i){
	int id_thread = (int)i;
	int begin, end;

	// on determine la portion du signal locale
	int local_signal_size = global_signal.size/nb_thread;

	begin = id_thread*local_signal_size;
	end = begin + local_signal_size ;
	if (id_thread == nb_thread-1){
		end = global_signal.size;
		local_signal_size = end-begin;
	}

	

	/* Lock a mutex prior to updating the value in the shared structure, and unlock it upon updating. */
	//pthread_mutex_lock (&mutexsum);
		printf("\n************ thread %d ***************\n", (int)i);
		double som, a;
		for (int b = begin; b<end ; b++){
			for (int i=0; i < global_scales.size; i++){
				som = 0;
				a=global_scales.values[i];
				
				for (int t = 0; t < global_signal.size; t++)
				{
					som +=  global_signal.values[t] * mex_hat((t-b)/a);
				}

				global_coefs.values[i][b] = som/sqrt(2);
			}
		}
	
	//pthread_mutex_unlock (&mutexsum);

	pthread_exit((void*) 0);
}

