CC = gcc
CFLAGS = -Wall
EXECUTABLE = dockspacer

all: $(EXECUTABLE)

$(EXECUTABLE): main.o create_dockspacer.o stoi.o
	$(CC) $(CFLAGS) main.o create_dockspacer.o stoi.o -o $(EXECUTABLE)

main.o: main.c
	$(CC) -c main.c

create_dockspacer.o: libs/create_dockspacer.c
	$(CC) -c libs/create_dockspacer.c

stoi.o: libs/stoi.c
	$(CC) -c libs/stoi.c

clean:
	rm *.o
