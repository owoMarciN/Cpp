# all:
	# g++ main.cpp Graphics.cpp GameManager.cpp GameEntity.cpp InputManager.cpp Timer.cpp Texture.cpp AssetManager.cpp AnimatedTexture.cpp -w -lSDL2 -lSDL2_image -lSDL2_ttf -o MyGame

# Directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := .

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -lSDL2 -lSDL2_image -lSDL2_ttf
INC := -I$(INC_DIR)

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Executable name
EXEC := my_program

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(EXEC) $(BUILD_DIR)/*.o

.PHONY: all clean
