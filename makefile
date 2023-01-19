CFLAGS = -g -Wall
OBJ = algo.o nodes.o edges.o
CC = gcc

all: output functions

algo.o: algo.c nodes.h algo.h edges.h
	$(CC) -c $(CFLAGS) algo.c

nodes.o: nodes.c nodes.h algo.h edges.h
	$(CC) -c $(CFLAGS) nodes.c

edges.o: edges.c nodes.h algo.h edges.h
	$(CC) -c $(CFLAGS) edges.c

libfunctions.so: $(OBJ)
	$(CC) -shared -fPIC -o libfunctions.so $(OBJ)

functions: libfunctions.so

main.o: main.c nodes.h algo.h edges.h
	$(CC) -c $(CFLAGS) main.c

output: main.o libfunctions.so
	$(CC) $(CFLAGS) -o algo main.o ./libfunctions.so

.PHONY: all clean functions output

clean:
	rm -f *.o *.so $(OUTPUT)
