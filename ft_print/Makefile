# Name of the library
NAME = libftprintf.a

#Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#assignment statements-source funcitons (string list creators) eg wlidcard pattern)
SRC =	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strlen.c



OBJ = $(SRC:.c=.o)

#rules
# 1 
all: $(NAME)

# 2 
$(NAME): $(OBJ)
	@ar rcs $@ $^ #the s flag runs a ranlib equivelent.

# 3 pattern rule creating/compiling the object files. 
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# 4 remove the object files
clean:
	@rm -rf $(OBJ)
	@echo "obj directory and all files removed!!"

# 5 removing the object files and default target
fclean: clean
	@rm -f $(NAME)
	@echo "fclean has completed!!"

# 6 rebuild refresh
re: fclean all

# Additional rule for compiling and running the test program
test: $(NAME)
	$(CC) $(CFLAGS) -o test main.c $(NAME)
	./test

.PHONY: all clean fclean re test
