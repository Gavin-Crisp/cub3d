NAME		:= $(notdir $(shell pwd))

SRC_DIR		:= .
SRCS		:= \
	add_back add_front clear find \
	find_closest index is_sorted iter \
	last map max min \
	new pop remove size \
	split_before split
SRCS		:= $(patsubst %,$(SRC_DIR)/ft_lst%.c,$(SRCS))

ifndef BUILD_DIR
_BUILD_DIR	:= .build
else
_BUILD_DIR	:= $(BUILD_DIR)/$(NAME)
endif

OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(_BUILD_DIR)/%.o,$(SRCS))
DEPS		:= $(patsubst %.o,%.d,$(OBJS))

CC			?= cc
CFLAGS		?= -Wall -Wextra -Werror
CPPFLAGS	:= -I $(ROOT) -MMD -MP

all: .finished_comp

.finished_comp: $(OBJS)
	touch $(_BUILD_DIR)/.finished_comp

$(_BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo CREATED $(@F)

-include $(DEPS)

clean:
	for f in $(OBJS); do if [ -f $$f ]; then rm $$f && echo "REMOVED $$(basename $$f)"; fi ; done
	rm -rf $(_BUILD_DIR)

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re
.SILENT:
