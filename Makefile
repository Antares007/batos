# === CONFIGURATION ===
ChapterSize := 16
CC      := clang
CFLAGS  := -Wall -Wextra -std=c99 -Iinclude -MMD -MP -DChapterSize=$(ChapterSize) -O3
SRC_DIR := .
OBJ_DIR := build
BIN_DIR := bin
TARGET  := $(BIN_DIR)/main
BOOKLD	:= $(OBJ_DIR)/book.ld
LDFLAGS := -Wl,-T$(BOOKLD),-Map=$(OBJ_DIR)/book.map

# === AUTOMATIC SOURCES & OBJECTS ===
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# === DEFAULT RULE ===
all: $(TARGET)

# === LINKING ===
$(TARGET): $(OBJS) | $(BIN_DIR) $(BOOKLD) 
	$(CC) $(LDFLAGS) $^ -o $@

$(BOOKLD):
	ld --verbose | sed -n '/^=========/,/^=========/{//!p}' > $(OBJ_DIR)/default.ld
	python patch_default_ld.py $(OBJ_DIR)/default.ld $(OBJ_DIR)/book.ld $(ChapterSize)

# === COMPILATION ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# === DIRECTORY CREATION ===
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# === CLEAN RULE ===
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# === RUN & DEBUG SHORTCUTS ===
run: all
	./$(TARGET)

debug: CFLAGS += -g -O3
debug: run

# === INCLUDE DEPENDENCIES ===
-include $(DEPS)

.PHONY: all clean run debug
