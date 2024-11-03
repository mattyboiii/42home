# Name of the library
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror

# assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

SRC = src/push_swap.c \
	src/utils/utils.c \
	src/utils/logicfunk.c \
	src/utils/logicfunk2.c \
	src/utils/logicfunk3.c \
	src/utils/logicfunk4.c \
	src/utils/lstfunk.c \
	src/utils/lstfunk2.c \
	src/utils/lstfunk3.c \
	src/utils/sortfunk.c \
	src/utils/stackfunk.c \
	src/utils/stackfunk2.c

# Rules
# 1
all: $(NAME)

#2 NAME rule
$(NAME): libft $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) -Llibft -lft

#3 creating the libft library.
libft:
	$(MAKE) -C libft

make:
	make

# 5 remove the object files
clean:
	@rm $(NAME)
	@echo "all files removed!!"

re: clean all

.PHONY: all clean re
