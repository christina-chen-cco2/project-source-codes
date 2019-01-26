project : getaddress.o userMenu.o menufunctions.o iofunctions.o main.o
	gcc -o project main.o getaddress.o userMenu.o iofunctions.o menufunctions.o 

main.o : main.c main.h
	gcc -ansi -pedantic-errors -Wall -c main.c

menufunctions.o : menufunctions.c functions.h
	gcc -ansi -pedantic-errors -Wall -c menufunctions.c

iofunctions.o : iofunctions.c functions.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

userMenu.o : userMenu.c userMenu.h
	gcc -ansi -pedantic-errors -Wall -c userMenu.c

getaddress.o : getaddress.c getaddress.h
	gcc -ansi -pedantic-errors -Wall -c getaddress.c

clear : 
	rm main.o userMenu.o iofunctions.o getaddress.o menufunctions.o
