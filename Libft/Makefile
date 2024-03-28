# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# assignment statements-Source funcitons (string list creators is really 
# what these are)-------------- eg $(wildcard pattern)

SRC = ft_atoi.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_itoa.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_memset.c \
      ft_putchar_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_putstr_fd.c \
      ft_split.c \
      ft_strchr.c \
      ft_strdup.c \
      ft_striteri.c \
      ft_strjoin.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_strlen.c \
      ft_strmapi.c \
      ft_strncmp.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strtrim.c \
      ft_substr.c \
      ft_tolower.c \
      ft_toupper.c

BONUS_SRC = ft_lstnew.c \
			ft_lstadd_front
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Rules
# 1 
all: $(NAME)

# 2 
$(NAME): $(OBJ)
	@ar rcs $@ $^ #the s flag runs a ranlib equivelent.

bonus: $(NAME) $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)

# 3 pattern rule creating/compiling the object files. 
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

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
