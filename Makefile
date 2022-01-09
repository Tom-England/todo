build:
	mkdir -p bin
	gcc -o bin/todo src/main.c src/file_handler.c
clean:
	rm bin/todo
	rm bin/todo.list
	rmdir bin