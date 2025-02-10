# Name of the library
NAME = pipex

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

SRC = src/pipex.c \
	src/pipex_utils.c \
	libft/libft.a

BONUS_SRC = src_bonus/pipex_bonus.c \
	    src_bonus/pipex_utils_bonus.c \
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
	@echo "All files removed!!"

fclean: clean
	@rm $(NAME);
	@echo "Project file removed!!"

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
