build:
	mkdir -p bin
	gcc -o bin/todo src/main.c src/file_handler.c src/todo_functions.c src/config.c src/linkedlist.c -O3
install:
	make build
	sudo mv bin/todo /bin/todo
clean:
	rm bin/todo
	rm bin/todo.list
	rmdir bin