#ifndef MAIN_H
#define MAIN_H
	#include "wavelet/wavelet.h"
	#include "utils/utils.h"
	#define SIGNAL_FNAME "csv_files/signal.csv"
	#define SCALES_FNAME "csv_files/scales.csv"

	clock_t start, end;
    unsigned long cpu_time(void);
	void init_cpu_time(void);

	void test_parallel(int nthreads);
	void test_sequential();
#endif