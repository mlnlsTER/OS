project: compile start delete
compile: os2.c
	g++ os2.c -o os2.o
start: os2.o
	./os2.o
delete: os2.o
	rm os2.o

