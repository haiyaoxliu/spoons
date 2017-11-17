all: naps.c
	gcc -o spork naps.c
	
run: all
	./spork