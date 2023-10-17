# Compiler
CXX := g++

# Source file
SOURCE := main.cpp

# Executable name
EXECUTABLE := second_largest_number

# Compile and link
$(EXECUTABLE) : $(SOURCE)
	$(CXX) -o $@ $<

clean:
	rm -f $(EXECUTABLE)

.PHONY : clean