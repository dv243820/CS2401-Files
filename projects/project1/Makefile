
CXX = g++

# Compiler flags
CXXFLAGS = -Wall

# Source files
SRCS = commented_main.cc check.cc checkbook.cc date.cc

# Output executable
TARGET = project1executable


$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -f *.txt $(TARGET)