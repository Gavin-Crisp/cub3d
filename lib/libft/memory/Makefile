export NAME		:= $(notdir $(shell pwd))

export SRC_DIR	:= .
SRCS			:= \
	bzero calloc memchr memcmp \
	memcpy memmove memset memswap \
	simple_realloc
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -C $(ROOT) -f component.mk

clean:
	$(MAKE) -C $(ROOT) -f component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
