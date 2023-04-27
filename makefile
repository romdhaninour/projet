CC = gcc
CFLAGS = -I/usr/include/SDL -g
LIBS = -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lSDL_gfx

all: prog

prog: enigme.o main.o 
	$(CC) enigme.o main.o -o prog $(LIBS) 

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c -o main.o

enigme.o: enigme.c enigme.h
	$(CC) $(CFLAGS) -c enigme.c -o enigme.o

clean:
	rm -f prog *.o

