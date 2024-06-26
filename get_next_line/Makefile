# Name of the library
NAME = tp.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

SRC = get_next_line.c \
      get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

# Test program
TEST_SRC = test/tprogram.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXEC = tp

# Rules
# 1 
all: $(NAME) $(TEST_EXEC)

# 2 
$(NAME): $(OBJ)
	@ar rcs $@ $^ # the s flag runs a ranlib equivalent

# 3 Pattern rule creating/compiling the object files
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -o $@ -c $<

# 4 Build the test program
$(TEST_EXEC): $(TEST_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) $(OBJ)

# 5 Remove the object files
clean:
	@rm -rf $(OBJ) $(TEST_OBJ)
	@echo "obj directory and all files removed!!"

# 6 Remove the object files and default target
fclean: clean
	@rm -f $(NAME) $(TEST_EXEC)
	@echo "fclean has completed!!"

# 7 Rebuild refresh
re: fclean all

# 8 Rebuild refresh bonus
rebonus: fclean bonus

# 9 Run the test program
run: $(TEST_EXEC)
	./$(TEST_EXEC)

.PHONY: all clean fclean re rebonus run
