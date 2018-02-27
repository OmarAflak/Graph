CC=g++

main: main.cpp include/* src/*
	$(CC) main.cpp -o main -I include/ src/*.cpp
