PROJECT=math3d

CXX=g++
AR=ar
CFLAGS=-std=c++11 -Iinclude/$(PROJECT)

OBJ=vector2.o vector3.o matrix4x4.o quaternion.o transform.o
SRC=$(OBJ:%.o=%.cpp)

GEN_BIN=test -d bin || mkdir bin

OUTPUT=bin/lib$(PROJECT).a

all: $(OUTPUT)

clean:
	test -d bin && rm -r bin

$(OUTPUT): $(OBJ)
	$(AR) rcs $(OUTPUT) $(OBJ:%=bin/%)

$(OBJ): $(SRC:%=src/%)
	$(GEN_BIN)
	$(CXX) -c src/$(@:%.o=%.cpp) -o bin/$@ $(CFLAGS)
