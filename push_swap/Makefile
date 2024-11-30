# Name of the library
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror

# assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

SRC = src/push_swap.c \
	src/Logic/logicfunk.c \
	src/Logic/logicfunk2.c \
	src/Logic/logicfunk3.c \
	src/Logic/logicfunk4.c \
	src/Logic/logicfunk5.c \
	src/List/lstfunk.c \
	src/List/lstfunk2.c \
	src/List/lstfunk3.c \
	src/utils/BasicSort.c \
	src/utils/error_check.c \
	src/utils/force_rotate.c \
	src/utils/manual_rotate.c \
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
