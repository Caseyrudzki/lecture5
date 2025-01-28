CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS =

# Output executable for tests
EXEC = test

# Source file
SRC = test.cpp  # Since all your code is in test.cpp now

# Object files
OBJ = test.o  # Only the object file for test.cpp is needed now

# Rule to build the test executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

# Compile test.cpp into an object file
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

# Clean the project
clean:
	rm -rf $(EXEC) *.o

# Run the tests
run_tests: $(EXEC)
	./$(EXEC)

.PHONY: clean run_tests
