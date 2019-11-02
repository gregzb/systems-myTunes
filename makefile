all: main.o llist.o music.o
	gcc -o program main.o llist.o music.o

main.o: main.c llist.h music.h
	gcc -c main.c llist.h music.h

llist.o: llist.c llist.h
	gcc -c llist.c llist.h

music.o: music.c music.h llist.h
	gcc -c music.c music.h llist.h

run:
	./program

memcheck:
	valgrind --leak-check=yes ./program
