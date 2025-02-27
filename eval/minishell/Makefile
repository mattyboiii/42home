# Compiler and flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror -Iinclude
# LDFLAGS = -Llibft -lft -lreadline

CFLAGS = -Wall -Wextra -Werror


LIBFT_DIR = libft
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LIB = -L$(LIBFT_DIR) -lft

RDLINE_DIR = /opt/homebrew/opt/readline
RDLINE_INC = -I$(RDLINE_DIR)/include
RDLINE_LIB = -L$(RDLINE_DIR)/lib -lreadline

# Directories
SRC_DIR = src
INC_DIR = include
LIBFT_DIR = libft
OBJ_DIR = obj

# Source and Object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Output binary
TARGET = minishell

# Rules
all: libft $(TARGET)

# Build target executable
$(TARGET): $(OBJS)
	@$(CC) $(OBJS) -o $@ $(LIBFT_LIB) $(RDLINE_LIB)

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) $(LIBFT_INC) $(RDLINE_INC)

# Build libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Clean up
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re libft
