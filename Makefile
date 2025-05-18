# === CONFIGURATION ===
CC      		:= clang
SRC_DIR 		:= .
OBJ_DIR 		:= build
BIN_DIR 		:= bin
TARGET  		:= $(BIN_DIR)/main
BOOKLD			:= $(OBJ_DIR)/book.ld
DEFAULTLD		:= $(OBJ_DIR)/default.ld
NMAP				:= $(OBJ_DIR)/name.map
LDFLAGS 		:= -Wl,-T$(BOOKLD),-Map=$(NMAP)
CFLAGS  		:= -Wall -Wno-unused-variable -std=c99 -Iinclude -MMD -MP -O3

# === AUTOMATIC SOURCES & OBJECTS ===
SRCS	:= $(wildcard $(SRC_DIR)/*.c)
OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
BOOKS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.b,$(SRCS))
DEPS	:= $(OBJS:.o=.d)

# === DEFAULT RULE ===
all: $(TARGET)

# === LINKING ===
$(TARGET): $(OBJS) | $(BIN_DIR) $(BOOKLD) 
	$(CC) $(LDFLAGS) $^ -o $@

$(DEFAULTLD): | $(OBJ_DIR)
	ld --verbose | sed -n '/^=========/,/^=========/{//!p}' > $(DEFAULTLD)

$(BOOKLD): patch_default_ld.py $(DEFAULTLD) $(BOOKS)
	python patch_default_ld.py $(DEFAULTLD) $(BOOKLD) $(BOOKS) 

# === COMPILATION ===
$(OBJ_DIR)/%.b: $(SRC_DIR)/%.c | $(OBJ_DIR)
	python chapter.py $< $@
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
