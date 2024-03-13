# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include

# Source funcitons (string list creators really is what these are) 
# -------------- eg $(wildcard pattern)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))


# Rules
# 1 
all: $(NAME)

# 2
$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

# 3 remove the object files
clean:
	@rm -rf $(OBJ)

# 4 removing the object files and target
fclean: clean
	@rm -f $(NAME)

#5 rebuild refresh
re: fclean all

.PHONY: all clean fclean re 

