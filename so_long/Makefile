# Name of the executable
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -g#-Wall -Wextra -Werror
LIBX = -Lminilibx-linux -lmlx -lXext -lX11
LIBFT = -Llibft -lft

# Assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

SRC =	src/so_long.c \
	src/pixel/pixelfunk.c \
	src/hook/hookfunk.c \
	src/utils.c \
	src/map.c \
	src/character/character_movement.c

# Generate object file names from source files
OBJ = $(SRC:.c=.o)

# Rules
# 1
all: $(NAME)

# 2 Create object files from source files
$(OBJ):	%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# 3 Create the executable from object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBX) $(LIBFT)
	@echo "\n"

# 4 Clean rule: Remove object files and executable
clean:
	rm -f $(OBJ) $(NAME)
	@echo "Object files and executable removed!!"

re: clean all
	@echo "Re compiled project"

.PHONY:	all clean re
