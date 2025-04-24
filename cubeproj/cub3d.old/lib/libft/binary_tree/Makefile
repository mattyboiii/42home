export NAME		:= binary_tree

export SRC_DIR	:= .
SRCS			:= \
	balance_factor balance clear height \
	insert_balanced insert is_balanced new \
	rotate_left rotate_right search size
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -C $(ROOT) -f component.mk

clean:
	$(MAKE) -C $(ROOT) -f component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
