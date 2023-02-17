mainmat : mainmat.o mymat.o inputCtrl.o
	gcc -g -ansi -Wall -pedantic mainmat.o mymat.o inputCtrl.o -o mainmat
mainmat.o : mainmat.c mymat.h inputCtrl.h
	gcc -c -ansi -Wall -pedantic mainmat.c -o mainmat.o
mymat.o : mymat.c inputCtrl.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o
inputCtrl.o : inputCtrl.c
	gcc -c -ansi -Wall -pedantic inputCtrl.c -o inputCtrl.o
