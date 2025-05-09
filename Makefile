# === CONFIGURATION ===
ChapterSize := 96
CC      		:= clang
CFLAGS  		:= -Wall -Wextra -std=c99 -Iinclude -MMD -MP -DChapterSize=$(ChapterSize) -O3
SRC_DIR 		:= .
OBJ_DIR 		:= build
BIN_DIR 		:= bin
TARGET  		:= $(BIN_DIR)/main$(ChapterSize)
BOOKLD			:= $(OBJ_DIR)/book$(ChapterSize).ld
DEFAULTLD		:= $(OBJ_DIR)/default.ld
LDFLAGS 		:= -Wl,-T$(BOOKLD),-Map=$(OBJ_DIR)/book$(ChapterSize).map

# === AUTOMATIC SOURCES & OBJECTS ===
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.$(ChapterSize).o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# === DEFAULT RULE ===
all: $(TARGET)

# === LINKING ===
$(TARGET): $(OBJS) | $(BIN_DIR) $(BOOKLD) 
	$(CC) $(LDFLAGS) $^ -o $@

$(DEFAULTLD): | $(BIN_DIR)
	ld --verbose | sed -n '/^=========/,/^=========/{//!p}' > $(DEFAULTLD)

$(BOOKLD): $(DEFAULTLD)
	python patch_default_ld.py $(DEFAULTLD) $(BOOKLD) $(ChapterSize)

# === COMPILATION ===
$(OBJ_DIR)/%.$(ChapterSize).o: $(SRC_DIR)/%.c | $(OBJ_DIR)
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
