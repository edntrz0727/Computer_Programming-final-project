all: src/main.c src/test.c
	gcc src/main.c -o engine
	gcc src/test.c -o test
clean:
	rm engine test