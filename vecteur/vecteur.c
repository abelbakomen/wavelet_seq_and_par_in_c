#include "vecteur.h"
#include <stdlib.h>
#include <stdio.h>

#include <time.h>

Vecteur new_vector(int size){
	Vecteur V;
	V.values = malloc(size * sizeof(double));
	V.size = size;

	return V;
}

int* arangeInt(int inf, int sup, int step){
	int size = (sup-inf)/step;
	size += 2;

	int* V = malloc(size * sizeof(int));

	V[0] = size;
	V[1] = inf;

	for (int i = 2; i < size; ++i)
		V[i] = inf + step;

	return V;
}

Vecteur arangeDouble(double inf, double sup, double step){
	int size = (int)((sup-inf)/step);
	size += 1;

	Vecteur V = new_vector(size);

	V.values[0] = inf;

	for (int i = 1; i < size; ++i)
		V.values[i] = inf+step;

	return V;
}

Vecteur generer_vecteur(int size, double min, double max){
	Vecteur V = new_vector(size);

	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		V.values[i] = -min + (double)rand() / (double)RAND_MAX *(max-min); 
	}

	return V;
}

void print_vect(Vecteur V){
	for (int i = 0; i < V.size; ++i)
	{
		printf("%f, ", V.values[i]);
	}
	return;
}

void to_csv_2_vect(Vecteur V1, Vecteur V2, const char* fname){
	FILE *file = fopen(fname,"w");
	char sep=' ';
	for (int i = 0; i < V1.size; ++i)
	 {
	 	fprintf(file, "%f%c%f\n", V1.values[i], sep, V2.values [i]);
	 } 

	fclose(file);
}

void to_csv_vect(Vecteur V,  const char* fname){
	FILE *file = fopen(fname,"w");

	for (int i = 0; i < V.size; ++i)
	 {
	 	fprintf(file, "%f\n", V.values[i]);
	 } 

	fclose(file);
}


Vecteur range(int min, int max){
    Vecteur r = new_vector(max-min);
    for (int i = 0; i < r.size; ++i)
    {
        r.values[i] = i;
    }

    return r;
}

Vecteur get_part(Vecteur X, int begin, int end){
    Vecteur part = new_vector(end-begin);

    for (int i = 0; i < part.size; ++i)
    {
        part.values[i] = X.values[begin+i];
    }

    return part;
}
