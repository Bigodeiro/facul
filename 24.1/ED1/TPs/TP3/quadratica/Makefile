all: tp.o automato.o quad_hash.o
	@gcc tp.o automato.o quad_hash.o -o exe
	@rm -r tp.o automato.o quad_hash.o
tp.o: tp.c
	@gcc tp.c -c -Wall
automato.o: automato.c
	@gcc automato.c -c -Wall
quad_hash.o: quad_hash.c
	@gcc quad_hash.c -c -Wall
val:
	@gcc -g -o exeval quad_hash.c automato.c tp.c -Wall
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval
run:
	@./exe
