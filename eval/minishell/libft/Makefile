# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = .
INCLUDES = -I$(SRCDIR)

# Source files
SRC_IS = $(wildcard ft_is/*.c)
SRC_IS_FILES = $(wildcard ft_is/*.c)
SRC_LST_FILES = $(wildcard ft_lst/*.c)
SRC_MEM_FILES = $(wildcard ft_mem/*.c)
SRC_PUT_FILES = $(wildcard ft_put/*.c)
SRC_STR_FILES = $(wildcard ft_str/*.c)
SRC_TO_FILES = $(wildcard ft_to/*.c)

SRC = $(SRC_IS_FILES) $(SRC_LST_FILES) $(SRC_MEM_FILES) $(SRC_PUT_FILES) $(SRC_STR_FILES) $(SRC_TO_FILES)
# Object files
OBJ = $(SRC:.c=.o)

# Library name
NAME = libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)

# Rule to compile source files into object files
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re $(NAME)
