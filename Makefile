all:
	make -C sort
	make -C search
	make -C dynamic_programming

clean:
	make -C sort clean
	make -C search clean
	make -C dynamic_programming clean

