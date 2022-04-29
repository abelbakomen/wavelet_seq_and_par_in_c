#implementation sequentielle et parallele de la transfomée en ondellete
#cas d'un signal à une dimention

#Requirements
    gcc
    genuplot

#Compillation
    make

#Excecution 
#  	Sequentielle
    		make run-seq
#	parallele
    		make run-par [nthreads="nombre de threads"]

# Structuration du projet
Le projet est organisé en differents modules dont le plus
important est "wavelet"
#   wavelet
        dans ce module sont implementés les versions séquentielles et parralles de la transformée en ondellete  d'un signal 1D
#   plot_script
        pour l'affichage des graphiques

# csv_file
        les données d'entrer et de sortie sont dans les fichiers csv.
        
# note : 
        executer le script exe.sh (./exe.sh) pour avoir le Speed-up et  l'efficacité
        Les résultats se trouvent dans le dossier output 
        