# Name of the executable
NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -g#-Wall -Wextra -Werror
LIBX = -Lminilibx-linux -lmlx -lXext -lX11
LIBFT = -Llibft -lft

# assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

SRC = src/so_long.c \
		src/pixel/pixelfunk.c \
		src/hook/hookfunk.c


# Rules
# 1
all: $(NAME)

#2 NAME rule
$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LIBX) $(LIBFT)
	@echo "\n"

# 3 remove the project file
clean:
	@rm $(NAME)
	@echo "Project file removed!!"

re: clean all
	@echo "Re compiled project"

.PHONY: all clean re
