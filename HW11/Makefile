all: prog

prog: main.o temp_api.o
	gcc -o prog main.o temp_api.o

main.o: main.c temp_api.h
	gcc -Wall -Wextra -std=c11 -c -o main.o main.c

temp_api.o: temp_api.c temp_api.h
	gcc -Wall -Wextra -std=c11 -c -o temp_api.o temp_api.c

clean:
	rm -f *.o prog
