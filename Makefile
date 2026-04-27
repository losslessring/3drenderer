build:
	gcc -g -Wall -std=c99 -I src/include -L src/lib -o main ./src/*.c -lmingw32 -lSDL2main -lSDL2

run:
	./renderer

clean:
	rm renderer 