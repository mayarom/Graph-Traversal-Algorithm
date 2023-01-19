CFLAGS = -g -Wall
OBJ = graph.o nodes.o edges.o
CC = gcc

all: output functions

graph.o: graph.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) graph.c

nodes.o: nodes.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) nodes.c

edges.o: edges.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) edges.c

libfunctions.so: $(OBJ)
	$(CC) -shared -fPIC -o libfunctions.so $(OBJ)

functions: libfunctions.so

main.o: main.c nodes.h graph.h edges.h
	$(CC) -c $(CFLAGS) main.c

output: main.o libfunctions.so
	$(CC) $(CFLAGS) -o graph main.o ./libfunctions.so

.PHONY: all clean functions output

clean:
	rm -f *.o *.so $(OUTPUT)
