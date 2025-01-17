# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# assignment statements-Source funcitons (string list creators is really
# what these are)-------------- eg $(wildcard pattern)

FT_PRINTF_SRC = ft_printf/ft_printf.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_putnbr_base.c \
				ft_printf/ft_putnbr.c \
				ft_printf/ft_putptr.c \
				ft_printf/ft_putstr.c \
				ft_printf/ft_strlen.c

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
      ft_toupper.c \
      ft_lstnew.c \
      ft_lstadd_front.c \
      ft_lstsize.c \
      ft_lstlast.c \
      ft_lstadd_back.c \
      ft_lstdelone.c \
      ft_lstclear.c \
      ft_lstiter.c \
      ft_lstmap.c \
      ft_strstr.c \
      ft_strcmp.c \
      null_free.c \
      dp_free.c \
      dp_strcat.c \
      ischar.c \
      get_next_line.c \
	  $(FT_PRINTF_SRC)

BONUS_SRC =

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Rules
# 1
all: $(NAME)

# 2
$(NAME): $(OBJ)
	@ar rcs $@ $^ #the s flag runs a ranlib equivelent.

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
