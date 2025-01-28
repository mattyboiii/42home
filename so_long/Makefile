# Name of the executable
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBX = -Lminilibx-linux -lmlx -lXext -lX11
LIBFT = -Llibft -lft

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

# Source files
SRC =	so_long.c \
		hookfunk.c \
		textures.c \
		utils.c \
		parse.c \
		window.c \
		free.c \
		check_map.c \
		check_movement.c \
		move_character.c \
		directions.c

# Generate object file names from source files
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

# Rules
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(LIBX)
	@echo "\nCompilation complete!"

# Clean rule: Remove object files and executable
clean:
	rm -rf $(OBJ_DIR) $(NAME)
	@echo "Object files, obj directory, and executable removed!"

re: clean all
	@echo "Re-compiled project"

.PHONY: all clean re
