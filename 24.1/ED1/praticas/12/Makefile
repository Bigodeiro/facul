all: pratica.o arvore.o
	@gcc pratica.o arvore.o -o exe
	@rm -r pratica.o arvore.o
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
arvore.o: arvore.c
	@gcc arvore.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval arvore.c pratica.c -Wall
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval