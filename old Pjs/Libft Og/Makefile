# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# assignment statements-Source funcitons (string list creators is really 
# what these are)-------------- eg $(wildcard pattern)

SRC =  src/ft_atoi.c/
src/ft_bzero.c/
src/ft_calloc.c/
src/ft_isalnum.c/
src/ft_isalpha.c/
src/ft_isascii.c/
src/ft_isdigit.c/
src/ft_isprint.c/
src/ft_itoa.c/
src/ft_memchr.c/
src/ft_memcmp.c/
src/ft_memcpy.c/
src/ft_memmove.c/
src/ft_memrchr.c/
src/ft_memset.c/
src/ft_putchar_fd.c/
src/ft_putendl_fd.c/
src/ft_putnbr_fd.c/
src/ft_putstr_ft.c/
src/ft_split.c/
src/ft_strchr.c/
src/ft_strdup.c/
src/ft_striteri.c/
src/ft_strjoin.c/
src/ft_strlcat.c/
src/ft_strlcpy.c/
src/ft_strlen.c/
src/ft_strmapi.c/
src/ft_strncmp.c/
src/ft_strnstr.c/
src/ft_strrchr.c/
src/ft_strtrim.c/
src/ft_substr.c/
src/ft_tolower.c/
src/ft_toupper.c/

OBJ = $(patsubst $%.c, $%.o, $(SRC))

# Rules
# 1 
all: $(NAME)

# 2 
$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@ #this line updates or creates a symbol index within the file its pointing to. in this case it is an archived library file.

# 3 pattern rule creating/compiling the object files. 
$%.o: $%.c
	$(CC) $(CFLAGS) -I. -o $@ -c $<

# 4 remove the object files
clean:
	@rm -rf $(OBJ)
	@echo "ojb directory and all files removed!!"

# 5 removing the object files and default target
fclean: clean
	@rm -f $(NAME)
	@echo "fclean has completed!!"

# 6 rebuild refresh
re: fclean all

.PHONY: all clean fclean re
