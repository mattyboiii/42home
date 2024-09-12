# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# assignment statements-Source funcitons (string list creators is really 
# what these are)-------------- eg $(wildcard pattern)

SRC = src/pipex.c \
      src/pipex_utils.c \
      libft/libft.a

BONUS_SRC = 		

# Rules
# 1 
all: $(NAME)

# 2 
$(NAME): $(SRC)
	CC CFLAGS $@

bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)

# 3 pattern rule creating/compiling the object files. 
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# 4 remove the object files
clean:
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJ)
	@echo "obj directory and all files removed!!"

# 5 removing the object files and default target
fclean: clean
	@rm -f $(NAME)
	@echo "fclean has completed!!"

# 6 rebuild refresh
re: fclean all

# 7 rebuild refresh bonus
rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
