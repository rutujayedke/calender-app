project: calender.o cmain.o
	cc calender.o cmain.o -o project -lncurses
calender.o: calender.c calender.h
	cc -c calender.c
cmain.o: cmain.c calender.h
	cc -c cmain.c -lncurses
clean:
	rm *.o

