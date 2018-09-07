CCC = g++

# Tracing flags
TFLAGS = 
# Debug related flags
DFLAGS =
# Optimization flags
OFLAGS = 

CFLAGS = $(DFLAGS) -Wall $(TFLAGS) $(OFLAGS)

OBJ_FOLDER=obj
BIN_FOLDER=bin

BOARD_HEADERS = Board.h 

BOARD_NAMES = Board.o

BOARD_OBJS = $(foreach obj, $(BOARD_NAMES), $(OBJ_FOLDER)/$(obj))

ALL_OBJS = $(BOARD_OBJS)

# trying to establish a way to compile individual object files so that DFLAGS can be set
# individually
.cpp.o:
	$(CCC) $(CFLAGS) -c -O $*.cpp

main: setup $(BOARD_OBJS) sudokuSolver.cpp
	$(info Building main solver)
	$(CCC) $(CFLAGS) -o $(BIN_FOLDER)/sudokuSolver $(BOARD_OBJS) sudokuSolver.cpp

$(ALL_OBJS): $(OBJ_FOLDER)/%.o : %.cpp %.h
	$(CCC) $(CFLAGS) -c $< -o $@

setup:
	if [ ! -d $(OBJ_FOLDER) ]; then mkdir $(OBJ_FOLDER); fi
	if [ ! -d $(BIN_FOLDER) ]; then mkdir $(BIN_FOLDER); fi

clean:
	rm -rf $(OBJ_FOLDER)/*
	rm -rf $(BIN_FOLDER)/*
