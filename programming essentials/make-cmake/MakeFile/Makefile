# --- Variables ---
CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = program
SOURCE = main.cpp
OBJECT = $(SOURCE:.cpp=.o) # main.o 
PREPROCESSED = $(SOURCE:.cpp=.i) # main.i

# --- Rules ---

# 1. Default Rule (Build the final executable)
all: $(TARGET)

# 2. Final Executable (.o to TARGET)
# Links the object file into the final executable
$(TARGET): $(OBJECT)
	$(CXX) $(OBJECT) -o $(TARGET)

# 3. Object File Rule (The .o file)
# Compiles the source file into an object file (machine code)
# This step does NOT include the linking phase.
$(OBJECT): $(SOURCE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 4. Preprocessed File Rule (The .i file)
# Creates the preprocessed file by expanding macros and including headers.
$(PREPROCESSED): $(SOURCE)
	$(CXX) -E $< -o $@

# 5. Clean Rule
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECT) $(PREPROCESSED)
