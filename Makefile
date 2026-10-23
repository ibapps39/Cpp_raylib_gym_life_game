CC = g++
CFLAGS = -g -O3 -Wall -std=c++17 -Wno-missing-braces
RAYLIB_PREFIX = /opt/homebrew/opt/raylib
LDFLAGS = -L$(RAYLIB_PREFIX)/lib -lraylib
INCLUDE_FOLDER = ./include
INCLUDES = -I$(RAYLIB_PREFIX)/include -I$(INCLUDE_FOLDER)

# Directory structure
SRC_DIR = ./src
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj

# Files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)
TARGET_NAME = PROJECT
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

# Create required directories
$(shell mkdir -p $(BUILD_DIR) $(OBJ_DIR))

all: $(TARGET)

# Link objects into executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile source files; -MMD -MP writes a .d file listing header dependencies
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

rebuild: clean all

# Pull in the generated dependency files (silently skip if missing)
-include $(DEP)

.PHONY: all clean rebuild