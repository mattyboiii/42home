# Name of the program
NAME = minishell

# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = -Llibft -lft

# Directories
LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj

# Create matching subdirectories for obj/
SUB_DIRS = $(sort $(dir $(OBJ)))

# Source files in src/ and its subdirectories
SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

# Object files in obj/, matching src structure
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Bonus source placeholders (currently unused)
BONUS_SRC = bonus_src
BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRC))

# Default rule
all: $(NAME)

# Build libft if needed
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

# Create subdirectories in obj/
$(SUB_DIRS):
	@mkdir -p $@

# Compile .c into .o, ensuring dirs exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(SUB_DIRS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Link objects into push_swap executable
$(NAME): $(LIBFT_DIR)/libft.a $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)
	@echo "\n $(NAME) Compilation complete!\n"

# Bonus rule (currently does nothing, but structure is kept)
bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $^

# Clean rule: Remove object files and executable
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\n $(NAME) $(OBJ_DIR) cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo " $(NAME) cleaned! fclean complete \n"



dclean: fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
	@echo " Re-compiled project. \n"

.PHONY: all clean fclean dclean re bonus rebonus
