NAME				:= libft.a

export ROOT			:= $(shell pwd)
export BUILD_DIR	:= $(ROOT)/.build

COMPONENTS			:= \
	binary_tree char converters \
	doubly_linked_list linked_list memory string \
	vector
COMP_CHECKS			:= $(patsubst %,$(BUILD_DIR)/%/.finished_comp,$(COMPONENTS))

export CC			?= cc
export CFLAGS		?= -Wall -Werror -Wextra

AR					= ar
ARFLAGS				= -rcs

MAKEFLAGS			+= --no-print-directory

ifndef INDENT
	export INDENT	:= 0
else
	export INDENT	:= $(shell echo $$(($(INDENT) + 1)))
endif
export INDENT_STYLE	?= "    "

define print
a=0; while [ $$a -lt $(INDENT) ]; do echo -n $(INDENT_STYLE); a=`expr $$a + 1`; done; echo $1
endef

all: $(NAME)

$(NAME): $(COMP_CHECKS)
	$(AR) $(ARFLAGS) $@ $(wildcard $(BUILD_DIR)/**/*.o)
	$(call print,CREATED $@)

$(BUILD_DIR)/%/.finished_comp:
	$(call print,$*)
	$(MAKE) -C $*

clean:
	$(call print,Cleaning libft...)
	for f in $(COMPONENTS); do $(call print,$$f); $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	$(call print,Done)

fclean:
	$(call print,Fully cleaning libft...)
	for f in $(COMPONENTS); do $(call print,$$f); $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	if [ -f $(NAME) ]; then rm $(NAME) && $(call print,REMOVED $(NAME)); fi
	$(call print,Done)

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette | grep -v OK || echo "All good"

.PHONY: all clean fclean re norm
.SILENT:
