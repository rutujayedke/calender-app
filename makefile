try: project.o main.o
	cc project.o main.o -o try
project.o: project.c project.h
	cc -c -o project.o project.c -lncurses
main.o: main.c project.h
	cc -c -o main.o main.c -lncurses

clean:
	rm *.o
