CC=g++
BIN=bin
OBJ=obj
SRC=src
FLAGS=--std=c++17

.PHONY: build clean

bin/raytracer: src/main.cpp obj/color.o obj/vec3.o obj/ray.o obj/sphere.o obj/hit_record.o
	[ -d $(BIN) ] || mkdir -p $(BIN)
	${CC} ${FLAGS} -o ${BIN}/raytracer ${SRC}/main.cpp ${OBJ}/color.o ${OBJ}/vec3.o ${OBJ}/ray.o ${OBJ}/sphere.o ${OBJ}/hit_record.o

obj/color.o: src/color.cpp src/color.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} ${FLAGS} -c -o ${OBJ}/color.o ${SRC}/color.cpp

obj/vec3.o: src/vec3.cpp src/vec3.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} ${FLAGS} -c -o ${OBJ}/vec3.o ${SRC}/vec3.cpp

obj/ray.o: src/ray.cpp src/ray.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} ${FLAGS} -c -o ${OBJ}/ray.o ${SRC}/ray.cpp

obj/sphere.o: src/sphere.cpp src/sphere.h src/hittable.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} ${FLAGS} -c -o ${OBJ}/sphere.o ${SRC}/sphere.cpp

obj/hit_record.o: src/hit_record.cpp src/hit_record.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} ${FLAGS} -c -o ${OBJ}/hit_record.o ${SRC}/hit_record.cpp

build: bin/raytracer

test: build.sh
	./build.sh tests

clean:
	rm -rf obj/
	rm -rf bin/
	rm -rf build/
