# Name of the library
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# assignment statements-Source funcitons (string list creators is really 
# what these are)-------------- eg $(wildcard pattern)

SRC = src/push_swap.c \
	src/push_swap.c \
	libft/libft.a

# Rules
# 1 
all: $(NAME)

#2 NAME rule
$(NAME): libft $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) -Llibft -lft

#3 creating the libft library. 
libft:
	$(MAKE) -C libft

# 4 Bonus
bonus: libft
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_SRC) -Llibft -lft

# 5 remove the object files
clean:
	@rm $(NAME)
	@echo "all files removed!!"

re: clean all

.PHONY: all clean re
