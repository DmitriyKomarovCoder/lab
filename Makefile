CC = g++
TARGET = main
CFLAGS= -Wall -Wextra -Werror
all: clean build ./main
build: GenerationBlockFile.o main.o
	$(CC) $(CFLAGS) GenerationBlockFile.o main.o -o $(TARGET)

main.o: main.cpp 
	$(CC) -c main.cpp

GenerationBlockFile.o: GenerationBlockFile.cpp
	$(CC) -c GenerationBlockFile.cpp

clean:
	rm -rf *.o build
