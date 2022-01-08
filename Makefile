build:
	mkdir -p bin
	gcc -o bin/todo src/main.c
clean:
	rm bin/todo
	rmdir bin