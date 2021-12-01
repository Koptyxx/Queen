CC = gcc
CFLAGS = -Wall -ansi
option = -lncurses

Dame: main.o graphique.o dame.o
	$(CC) -o $@ $^ $(CFLAGS) $(option)

main.o: main.c graphique.o dame.c

graphique.o: graphique.c structures.h include.h

dame.o: dame.c structures.h

%o: %.c 

clear:
	rm *.o
	rm Dame