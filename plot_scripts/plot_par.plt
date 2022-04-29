#plot.plt
set term qt 1
set ylabel 'Y' 
set xlabel 'X'

#set multiplot layout 2,1 rowsfirst
	 
	set view map
	set title 'wavelet transform coefficients: Parallel version'

	splot 'csv_files/seq_coefs.csv' matrix w pm3d notitle
#unset multiplot 
