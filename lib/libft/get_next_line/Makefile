export NAME		:= $(notdir $(shell pwd))

export SRC_DIR:= srcs
SRCS		:= get_next_line utils
export SRCS		:= $(patsubst %,$(SRC_DIR)/%.c,$(SRCS))

export CPPFLAGS	:= $(addprefix -I ,$(ROOT) $(ROOT)/$(NAME)/include) -MMD -MP

all:
	$(MAKE) -C $(ROOT) -f component.mk

clean:
	$(MAKE) -C $(ROOT) -f component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
