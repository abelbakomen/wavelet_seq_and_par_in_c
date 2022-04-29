#ifndef UTIL_H 
#define  UTIL_H
	#include "../vecteur/vecteur.h"

	#include <sys/time.h>
	#include<string.h>
	#include<math.h>
	#include <pthread.h>
	#include <ctype.h>
	#include <limits.h>

	#include <stdio.h>
	#include <stdlib.h>


	Vecteur importer_vecteur(char * fileName);

	void init_cpu_time(void);
	unsigned long cpu_time(void);


#endif