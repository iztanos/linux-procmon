CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

TARGET = procmon

SRC = src/main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

run: all
	./$(TARGET)
