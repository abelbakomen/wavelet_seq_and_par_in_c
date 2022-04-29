#ifndef MATRICE_H
#define MATRICE_H 
	
	typedef struct Matrice
	{
	    double ** values;
	    int shape [2];   
	}Matrice;

	Matrice generer_matrice(int r, int c, double min, double ma);
    Matrice new_matrice(int r, int c);
    void to_csv_mat(Matrice M, const char* fname);
    
    void print_mat(Matrice M);
#endif