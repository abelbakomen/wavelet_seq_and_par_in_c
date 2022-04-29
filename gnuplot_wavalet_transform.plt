#set term postscript color noenhanced
set term pdf color noenhanced
set output output_file
set grid
#set format ''

# color definitions
set style line 3 lc rgb 'red'      lw 2 dt 8 pt 5
set style line 2 lc rgb 'black'     lw 2 dt 7 pt 3
set style line 1 lc rgb 'blue'    lw 3 dt 5 pt 5

set xlabel 'Number of Thread'
set ylabel 'Time (s)'
#set yrange [1:2000]

set title "Wine Quality time ";
set ylabel 'Time  (s)'

#set term_astro.pdf color noenhanced
#set output output_file
#images save in ../../../../../images/ (pwd = ... courbes/load_balancing/load_30-12-2016/com-astro_new/com-astro_with_numbering_algo_29-012017)

set output "output/excecution_time.pdf" 
plot input_file using 1:2 t 'Execution Time' w lines linestyle 1

#...........................................................................................................................................
#images save in ../../../../../images/ (pwd = ... courbes/load_balancing/load_30-12-2016/com-astro_new/com-astro_with_numbering_algo_29-012017)
set output "output/speedup_wavalet_transform.pdf" 
set title "Speed-Up Wavelet transform";
set ylabel 'speed-up'
plot input_file using 1:(8.376 /$2) t 'Wavelet transform' w lines linestyle 1

#...................
set output "output/efficiency_wavalet_transform.pdf" 
set title "Efficiency Wavelet transform";
set ylabel 'efficiency'

plot input_file using 1:(8.376 /($1*$2)) t 'Wavelet transform' w lines linestyle 1