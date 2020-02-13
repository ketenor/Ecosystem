CFLAGS := -g -Wall

all:  tests_ecosys ecosys

tests_ecosys: ecosys.o main_tests.o
	gcc $(CFLAGS) -o test_ecosys ecosys.o main_tests.o

ecosys : main_ecosys.o ecosys.o
	gcc $(CFLAGS) -o ecosys main_ecosys.o ecosys.o

ecosys.o: ecosys.c ecosys.h
	gcc $(CFLAGS) -c ecosys.c

main_tests.o: main_tests.c
	gcc $(CFLAGS) -c main_tests.c

main_ecosys.o: main_ecosys.c
	gcc  $(CFLAGS) -c main_ecosys.c

clean:
	rm -f *.o *~ $(PROGRAMS)
