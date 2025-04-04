# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj

# All .c source files inside src and its subdirs (like ft_printf)
SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

# Generate object files in obj/ from source files
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Bonus source placeholders (currently unused)
BONUS_SRC =
BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRC))

# Default rule
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Archive all .o into libft.a
$(NAME): $(OBJ)
	@ar rcs $@ $^

# Bonus rule (currently does nothing, but structure is kept)
bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $^

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files and obj directory removed."

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "fclean complete."

# Rebuild from scratch
re: fclean all

# Rebuild bonus from scratch
rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
