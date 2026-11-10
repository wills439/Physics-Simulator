OBJS = src/main.cpp
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = physicssim

all:
	$(CC) $(OBJS) $(CXXFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)