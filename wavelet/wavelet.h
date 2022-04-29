#ifndef MODEL_H

#define MODEL_H
#include "../vecteur/vecteur.h"
#include "../matrice/matrice.h"
#include<pthread.h>

// --------------- Modele -----------

	#define SIGNAL_LEN 100
	#define SCALES_LEN 50
	#define TRANSLATES_LEN 100

	int nb_thread;
	
	Vecteur global_signal;
	Vecteur global_scales;

	Matrice global_coefs;

	pthread_mutex_t mutexsum;

	double mex_hat(double t);


	Matrice cwt_1d(Vecteur f, char* phi, Vecteur scales);
	void parallel_cwt_1d(int nb_thrd);
	void* thread_cwt( void* i);

#endif