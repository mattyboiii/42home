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
		src/hookfunk.c \
		src/textures.c \
		src/utils.c \
		src/parse.c \
		src/window.c \
		src/free.c \
		src/check_map.c \
		src/movement/check_movement.c \
		src/movement/move_character.c \
		src/movement/directions.c

# Generate object file names from source files
OBJ_DIR = src/obj
OBJ = $(SRC:.c=.o)

# Rules
# 1
all: $(NAME)

# 2 Create object files from source files
$(OBJ):	%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# 3 Create the executable from object files
$(NAME): $(OBJ)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT) $(LIBX)
	@echo "\n"

# 4 Clean rule: Remove object files and executable
clean:
	rm -f $(OBJ) $(NAME)
	@echo "Object files and executable removed!!"

re: clean all
	@echo "Re compiled project"

.PHONY:	all clean re
