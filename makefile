all: src/main.c
	gcc src/main.c -o engine
clean:
	rm engine