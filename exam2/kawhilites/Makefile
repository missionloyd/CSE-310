EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC): main.o heap.o
	$(CC) -o $(EXEC) main.o heap.o

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

heap.o: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean:
	rm *.o run


