all :
	gcc -o P P.c
	gcc -o C C.c
	./C
	./P

p :
	gcc -o P P.c
	./P

c :
	gcc -o C C.c
	./C

clean :
	rm -rf P C