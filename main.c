#include "main.h"
typedef struct timezone timezone_t;
typedef struct timeval timeval_t;

timeval_t t1, t2;
timezone_t tz;


static struct timeval _t1, _t2;
static struct timezone _tz;
timeval_t t1, t2;
timezone_t tz;

static unsigned long _temps_residuel = 0;
unsigned long cpu_time_used;

#define top1() gettimeofday(&_t1, &_tz)
#define top2() gettimeofday(&_t2, &_tz)



int main(int argc, char *argv[])
{
    /* 
        argv[1] contient le mode d'execution
        argv[2] contient le nombre de thread pour la version parralle
    */

    if (argc <2){
        puts("specify execution mode from \n\t -par\n\t -seq");
        return 1;
    }
    
    if (strcmp(argv[1],"-seq")==0)
        test_sequential();

    if (strcmp(argv[1],"-par")==0)
    {
        int nthreads;
        if (argc <3)
            nthreads=2;
        else
            sscanf(argv[2], "%d", &nthreads);
        
        test_parallel(nthreads);
    }

    return 0;
}

void test_parallel(int nthreads){

    //importation des donnees
    global_signal = importer_vecteur(SIGNAL_FNAME);
    global_scales = importer_vecteur(SCALES_FNAME);

    //calcul  parallele des coefficient
    
top1();
    parallel_cwt_1d(nthreads);
top2();

    cpu_time_used = cpu_time();
    printf("\n--------- Temps d'execution = %ld.%03lds\n", cpu_time_used/CLOCKS_PER_SEC, cpu_time_used%1000);
 
    to_csv_mat(global_coefs, "csv_files/par_coefs.csv");
    
    system("gnuplot -p plot_scripts/plot_par.plt");
    
}

void test_sequential(){
   
    //importation des donnees
    global_signal = importer_vecteur(SIGNAL_FNAME);
    global_scales = importer_vecteur(SCALES_FNAME);

top1();
    global_coefs = cwt_1d(global_signal, "haar" ,global_scales);
top2();
    
    cpu_time_used = cpu_time();
    printf("\n--------- Temps d'execution = %ld.%03lds\n", cpu_time_used/CLOCKS_PER_SEC, cpu_time_used%1000);
    
    //print_mat(global_coefs);

    to_csv_mat(global_coefs, "csv_files/seq_coefs.csv");    
    
    //to_csv_2_vect(X, Y_pred, "csv_files/seq/X_Ypred.csv");
    //to_csv_2_vect(Y, Y_pred, "csv_files/seq/Y_Ypred.csv");
    //to_csv_2_vect(range(0,loss.size), loss, "csv_files/seq/loss.csv");
    
    system("gnuplot -p plot_scripts/plot_seq.plt");
    
}
void init_cpu_time(void)
{
   top1(); top2();
   _temps_residuel = 1000000L * _t2.tv_sec + _t2.tv_usec -
                     (1000000L * _t1.tv_sec + _t1.tv_usec );
}

unsigned long cpu_time(void) /* retourne des microsecondes */
{
   return 1000000L * _t2.tv_sec + _t2.tv_usec -
           (1000000L * _t1.tv_sec + _t1.tv_usec ) - _temps_residuel;
}

