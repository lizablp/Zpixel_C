CC=gcc
CFLAGS=`pkg-config --cflags gmodule-2.0` -ggdb -g -Wall
LIBS=`pkg-config --libs gmodule-2.0` -lm

testzpixeltree:
	$(CC) $(CFLAGS) testzpixeltree.c zpixel.c zpixeltree.c
$(LIBS) -o testzpixeltree

testzpixel:
	$(CC) $(CFLAGS) testzpixel.c zpixel $(LIBS) -o testzpixel
