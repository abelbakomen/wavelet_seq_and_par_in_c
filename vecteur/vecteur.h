#ifndef VECTEUR_H

#define VECTEUR_H
	
	typedef struct Vecteur
	{
		double * values;
		int size; 		
	}Vecteur;

	Vecteur generer_vecteur(int size, double min, double max);
    Vecteur new_vector(int size);
    Vecteur range(int min, int max);
    Vecteur get_part(Vecteur X, int begin, int end);
    
    void print_vect(Vecteur V);	
    void to_csv_2_vect(Vecteur V1, Vecteur V2, const char* fname);
    void to_csv_vect(Vecteur V, const char* fname);
#endif

