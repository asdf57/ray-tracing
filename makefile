CC=g++
BIN=bin
OBJ=obj
SRC=src
FLAGS=--std=c++17

.PHONY: build clean

bin/raytracer: src/main.cpp
	[ -d $(BIN) ] || mkdir -p $(BIN)
	${CC} ${FLAGS} -o ${BIN}/raytracer ${SRC}/main.cpp

build: bin/raytracer

clean:
	rm -rf obj/
	rm -rf bin/
