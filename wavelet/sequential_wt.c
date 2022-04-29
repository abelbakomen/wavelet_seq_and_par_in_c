#include "wavelet.h"
#include <math.h>
#include <stdio.h>

Matrice cwt_1d(Vecteur f, char* phi, Vecteur scales){
	printf("*************** SEQUENTIAL VERSION WAVELET TRANSFORM ******************\n\n");
	Matrice coefs = new_matrice(scales.size, f.size);

	double som, a;
	for (int b = 0; b<f.size ; b++){
		for (int i=0; i < scales.size; i++){
			som = 0;
			a=scales.values[i];
			
			for (int t = 0; t < f.size; t++)
			{
				som +=  f.values[t] * mex_hat((t-b)/a);
			}

			coefs.values[i][b] = som/sqrt(2);
		}
	}

	return coefs;
}

double mex_hat(double t){
	return ((1-pow(t,2))*exp(-pow(t,2)/2));
}
