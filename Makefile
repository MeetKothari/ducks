ducks : main.o circular.o interface.o
	gcc -g -o ducks -ansi -Wall main.o circular.o interface.o

main.o : main.c globals.h interface.h circular.h
	gcc -g -c -ansi -Wall main.c

interface.o : interface.c circular.h globals.h
	gcc -g -c -ansi -Wall interface.c

circular.o : circular.c circular.h
	gcc -g -c -ansi -Wall circular.c
	
clean :
	rm -f *.o ducks
