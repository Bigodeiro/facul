all: pratica.o ordenacao.o
	@gcc pratica.o ordenacao.o -o exe
	@rm -r pratica.o ordenacao.o
pratica.o: pratica.c
	@gcc pratica.c -c
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c
run:
	@./exe
val:
	@gcc -g -o exeval ordenacao.c pratica.c -Wall
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval
