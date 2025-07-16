# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Source files
SRCS = main.cpp tx.cpp rx.cpp channel.cpp config.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = my_csim

# Build rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
