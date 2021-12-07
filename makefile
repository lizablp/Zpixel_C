cc=gcc

prog: testzpixels.o zpixels.o
	$(cc) testzpixels.o zpixels.o -o prog -lm

testzpixels.o: testzpixels.c zpixels.h
	$(cc) -c testzpixels.c

zpixels.o:  zpixels.c zpixels.h
	$(cc) -c zpixels.c
