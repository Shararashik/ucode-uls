# Compiler and Compilation Flags
CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -pedantic -g

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc

# Source, Object, and Header Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
INC_FILES := $(wildcard $(INC_DIR)/*.h)

# Archive and Archive Flags
AR := ar
AFLAGS := rcs

# Commands
MKDIR := mkdir -p
RM := rm -rf

# Target Executable
NAME := libmx.a

# Phony Targets
.PHONY: all clean uninstall reinstall

# Default Target
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $(AFLAGS) $@ $^
	@echo "[$(NAME)] Archive created successfully."

# Compile C Source Files into Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
	@echo "[$(NAME)] Compiled: $<"

$(OBJ_DIR):
	@$(MKDIR) $@

# Clean Object Files
clean:
	@$(RM) $(OBJ_DIR)
	@echo "[$(NAME)] Cleaned."

# Remove Object Files and Executable
uninstall: clean
	@$(RM) $(NAME)
	@echo "[$(NAME)] Uninstalled."

# Rebuild the Library
reinstall: uninstall all
