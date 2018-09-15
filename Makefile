CCC = g++

# Tracing flags
TFLAGS = 
# Debug related flags
DFLAGS = -g
# Optimization flags
OFLAGS = 

CFLAGS = $(DFLAGS) -Wall $(TFLAGS) $(OFLAGS)

OBJ_FOLDER=obj
BIN_FOLDER=bin
RULE_FOLDER=Rules

SOLVER_HEADERS = Board.h Solver.h
SOLVER_NAMES = Board.o Solver.o
SOLVER_OBJS = $(foreach obj, $(SOLVER_NAMES), $(OBJ_FOLDER)/$(obj))

RULE_NAMES = BasicRules.o
RULE_OBJS = $(foreach obj, $(RULE_NAMES), $(OBJ_FOLDER)/$(obj))

ALL_OBJS = $(SOLVER_OBJS) 

main: setup $(ALL_OBJS) $(RULE_OBJS) SudokuSolver.cpp
	$(info Building main solver)
	$(CCC) $(CFLAGS) -o $(BIN_FOLDER)/SudokuSolver $(ALL_OBJS) $(RULE_OBJS) SudokuSolver.cpp

$(RULE_OBJS): $(OBJ_FOLDER)/%.o : $(RULE_FOLDER)/%.cpp $(RULE_FOLDER)/Rule.h
	echo "$(CCC) $(CFLAGS) -c $< -o $@"
	$(CCC) $(CFLAGS) -c $< -o $@

$(ALL_OBJS): $(OBJ_FOLDER)/%.o : %.cpp %.h
	echo "$(CCC) $(CFLAGS) -c $< -o $@"
	$(CCC) $(CFLAGS) -c $< -o $@

setup:
	if [ ! -d $(OBJ_FOLDER) ]; then mkdir $(OBJ_FOLDER); fi
	if [ ! -d $(BIN_FOLDER) ]; then mkdir $(BIN_FOLDER); fi

clean:
	rm -rf $(OBJ_FOLDER)/*
	rm -rf $(BIN_FOLDER)/*
