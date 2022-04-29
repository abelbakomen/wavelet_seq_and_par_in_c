all:*.c *.h  */*.c */*.h
	gcc-9 -g -o test *.c */*.h */*.c -lm -lpthread
run-seq:
	./test -seq
run-par:
	./test -par $(nthreads)
clean:
	rm test
