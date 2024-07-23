# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

# Source files
SRC = get_next_line.c \
      get_next_line_utils.c \

# Test program
TEST_SRC = test/tprogram.c
TEST_EXEC = tp

# Rules
# 1 Compile the test program
all: $(TEST_EXEC)

# 2 Compile the test program with the source files
$(TEST_EXEC): $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(TEST_SRC)

# 3 Remove the executable
clean:
	@rm -f $(TEST_EXEC)
	@echo "Executable removed!"

# 4 Rebuild
re: clean all

# 5 Run the test program
run: $(TEST_EXEC)
	./$(TEST_EXEC)

.PHONY: all clean re run
