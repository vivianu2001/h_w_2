libmatrix.a: my_mat.o
	ar rcs libmatrix.a my_mat.o


my_mat.o : my_mat.c my_mat.h												
	gcc  -c -fPIC -Wall  my_mat.c 

main.o: main.c my_mat.h
	gcc  -c -fPIC -Wall main.c 

connections: libmatrix.a main.o
	gcc main.o -L -lmatrix -o connections


clean :
	rm -f *.o
all: connections