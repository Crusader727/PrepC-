binary: main.o libfile.a
	gcc -o main main.o -L. -lfile

main.o: main.c
	gcc -c main.c

libfile.a: file.o
	ar cr libfile.a file.o

file.o: file.c
	gcc -c file.c

clean:
	rm -f *.o *.a *.out binary
