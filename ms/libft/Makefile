# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
FT_PRINTF_DIR = src/ft_printf
SRC_DIR = src
OBJ_DIR = obj

# Include directories variable
INCLUDES := -I. -I$(FT_PRINTF_DIR)

# Create necessary directories for each object file
SUB_DIRS = $(sort $(dir $(OBJ)))

# All .c source files inside src and its subdirs (like ft_printf)
SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

# Generate object files in obj/ from source files
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Bonus source placeholders (currently unused)
BONUS_SRC = bonus_src
BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRC))

# Default rule
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# create dependancy files, and include them
DEP := $(OBJ:.o=.d)
-include $(DEP)

$(SUB_DIRS):
	@mkdir -p $@

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(SUB_DIRS)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

# Archive all .o into libft.a
$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "\n $(NAME) compilation complete!\n"

# Bonus rule (currently does nothing, but structure is kept)
bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $^

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\n $(NAME) $(OBJ_DIR) cleaned!"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo " $(NAME) cleaned! fclean complete \n"

# Rebuild from scratch
re: fclean all

# Rebuild bonus from scratch
rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
