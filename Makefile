# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Source files
SRCS = main.cpp tx/tx.cpp rx/rx.cpp channel/channel.cpp config.cpp common.cpp

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
