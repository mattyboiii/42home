# Name of the library
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = -Llibft -lft

# Directories
SRC_DIR = src
OBJ_DIR = obj

# assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)
SRC =	push_swap.c \
		logicfunk.c \
		logicfunk2.c \
		logicfunk3.c \
		logicfunk4.c \
		logicfunk5.c \
		lstfunk.c \
		lstfunk2.c \
		lstfunk3.c \
		BasicSort.c \
		error_check.c \
		force_rotate.c \
		force_rotate2.c \
		manual_rotate.c \
		sortfunk.c \
		stackfunk.c \
		stackfunk2.c

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

fclean:clean
	rm -rf $(NAME)

re: clean all
	@echo "Re-compiled project"
