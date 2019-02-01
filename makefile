build:

	gcc -Wall -Wpedantic -std=c11 -o executable main.c

run:

	./executable

buildrun: build run 
