# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include

# assignment statements-Source funcitons (string list creators is really 
# what these are)-------------- eg $(wildcard pattern)
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Rules
# 1 
all: $(NAME)

# 2 
$(NAME): $(OBJ)
	@ar rc $@ $<
	@ranlib $@ #this adds or updates the index within the target. often adding __.SYMDEF for SYMBOL DEFINITION

# 3 pattern rule creating/compiling the object files. 
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

# 4 remove the object files
clean:
	@rm -rf $(OBJ)

# 5 removing the object files and target
fclean: clean
	@rm -f $(NAME)

# 6 rebuild refresh
re: fclean all


.PHONY: all clean fclean re



