#include "../utils/utils.h"
#include "../vecteur/vecteur.h"


Vecteur importer_vecteur(char * fileName){
    Vecteur data;

    FILE *file = NULL;
    file = fopen(fileName, "r");

    char ligne[64];
    float token = 0;
    int size=0;
    int i=0;

    if (file == NULL){
        printf("erreur : impossible d'ouvrir le ficher [%s]\n",fileName);
        exit(0);
    }
    
  
    fscanf(file, "%s", &ligne);
    sscanf(ligne, "%d", &size);
    data = new_vector(size);
    
    while (fscanf(file, "%s", &ligne) != EOF && i<data.size)
    {    
        sscanf(ligne, "%f", &token); 
        data.values[i] = token;
        i++;
    }

    data.size=i;

    //print_vect(data);
    fclose(file);
    return data;   
}


//fonction pour importer le dataset
double **importerDataset(int size)
{
    static  double **data;

    data = malloc(sizeof( double) * 2);
    data[0] = malloc(sizeof( double) * size);
    data[1] = malloc(sizeof( double) * size);

    FILE *file = NULL;
    file = fopen("csv_files/data_regression_lineaire2.csv", "r");

    char ligne[64];
    char *value;
    float token = 0;

    if (file == NULL)
    {
        printf("erreur : impossible d'ouvrir le ficher\n");
        exit(0);
    }
    if (fgets(ligne, 64, file) != NULL)
        ; // on ignore la première ligne
    // a chaque appel de fgets on passe a la prochaine ligne du fichier
    //on parcour le fichier puis on recupere les donnees
    for (size_t i = 0; i < size; i++)
    {
        if (fgets(ligne, 64, file) != NULL)
        {
            value = strtok(ligne, ","); //on lit les chaines de caracteres jusqu'au seperateur

            if (value != NULL)
            {
                //printf("%s , ", value);
                token = atof(value); //convertion du sting en float
                data[0][i] = token;
                value = strtok(NULL, ",");
            }
            if (value != NULL)
            {
                //printf("%s , ", value);
                token = atof(value);
                data[1][i] = token;
                value = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    return data;
}

