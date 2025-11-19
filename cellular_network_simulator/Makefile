# Makefile for Cellular Network Simulator

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

# Source directories
CORE_DIR = core
NETWORKS_DIR = networks
UTILS_DIR = utils

# Source files
CORE_SRCS = $(wildcard $(CORE_DIR)/*.cpp)
NETWORKS_SRCS = $(wildcard $(NETWORKS_DIR)/*.cpp)
UTILS_SRCS = $(wildcard $(UTILS_DIR)/*.cpp) # Now includes Basicio.cpp and HelperFunctions.cpp
MAIN_SRC = main.cpp

SRCS = $(MAIN_SRC) $(CORE_SRCS) $(NETWORKS_SRCS) $(UTILS_SRCS)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = simulator

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	del $(subst /,\,$(OBJS)) $(TARGET).exe

.PHONY: all clean
