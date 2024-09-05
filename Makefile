CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := Server

# created target var for more clear execution
TARGET := $(BIN)/$(EXECUTABLE)


all: $(TARGET)

run: clean all
	clear
	./$(TARGET)

$(TARGET): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*