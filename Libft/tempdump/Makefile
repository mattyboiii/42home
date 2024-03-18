# name variable for output file
NAME = libft.a

# compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#directories
SRCDIR = src
OBJDIR = obj
INCDIR = include

# list generator functions. 
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Rules

#1
all: $(NAME)

#2
$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

# 3 compiling rule
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

# 4
clean:
	@rm -rf $(OBJDIR)

# 5
fclean: clean
	@rm -f $(NAME)

# 6
re: fclean all

#phony rule specifier. 
.PHONY: all clean fclean re
