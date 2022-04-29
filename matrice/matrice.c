#include "matrice.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


Matrice new_matrice(int r, int c){
	Matrice M;
	
	M.shape[0]=r;
	M.shape[1]=c;

	M.values = malloc(r * sizeof(double*));

	for (int i = 0; i < r; ++i)
		M.values[i] = malloc(c * sizeof(double));
		
	return M;
}

Matrice generer_matrice(int r, int c, double min, double max){
	Matrice M = new_matrice(r,c);

	srand(time(NULL));	
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			M.values[i][j] = 	-min + (double)rand() / (double)RAND_MAX *(max-min); 
		}
	}

	return M;
}


void print_mat(Matrice M){
	
	for (int i = 0; i < M.shape[0]; ++i)
	{
		for (int j = 0; j < M.shape[1]; ++j)
		{
			printf("%f  ", M.values[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}


void to_csv_mat(Matrice M, const char* fname){
	FILE *file = fopen(fname,"w");
	char sep=' ';
	for (int i = 0; i < M.shape[0]; ++i){
		for (int j = 0; j < M.shape[1] - 1; ++j)
	 		fprintf(file, "%f%c", M.values[i][j], sep);
	 	(i < M.shape[0] - 1) ? fprintf(file, "%f\n", M.values[i][M.shape[1]-1]) : fprintf(file, "%f", M.values[i][M.shape[1]-1]);
	}
	
	fclose(file);
}