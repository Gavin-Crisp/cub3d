export NAME		:= $(notdir $(shell pwd))

export SRC_DIR	:= .
SRCS			:= \
	add_back add_front clear find \
	find_closest index is_sorted iter \
	last map max min \
	new pop remove size \
	split_before split
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_lst%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -C $(ROOT) -f component.mk

clean:
	$(MAKE) -C $(ROOT) -f component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
