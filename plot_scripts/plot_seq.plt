#plot.plt
set term qt 1

#set multiplot layout 2,1 rowsfirst
	set view map
	set title 'wavelet transform coefficients: Sequential version'
	splot 'csv_files/seq_coefs.csv' matrix w pm3d notitle


#unset multiplot

