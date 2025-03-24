export NAME		:= $(notdir $(shell pwd))

export SRC_DIR	:= .
SRCS			:= \
	split strchr strchrs strcmp \
	strcount strdup stris_numeric striteri \
	strjoin strlcat strlcpy strlen \
	strmapi strncmp strndup strnstr \
	strrchr strtoupper strtrim substr
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -C $(ROOT) -f component.mk

clean:
	$(MAKE) -C $(ROOT) -f component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
