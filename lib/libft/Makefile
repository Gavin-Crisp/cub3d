NAME				:= libft.a

export ROOT			:= $(shell pwd)
export BUILD_DIR	:= $(ROOT)/.build

COMPONENTS			:= \
	allocator binary_tree char converters \
	doubly_linked_list linked_list memory string
COMP_CHECKS			:= $(patsubst %,$(BUILD_DIR)/%/.finished_comp,$(COMPONENTS))

export CC			?= cc
export CFLAGS		?= -Wall -Werror -Wextra

AR					= ar
ARFLAGS				= -rcs

MAKEFLAGS			+= --no-print-directory

all: $(NAME)

$(NAME): $(COMP_CHECKS)
	$(AR) $(ARFLAGS) $@ $(wildcard $(BUILD_DIR)/**/*.o)
	echo CREATED $@

$(BUILD_DIR)/%/.finished_comp:
	$(MAKE) -C $*

clean:
	echo Cleaning libft...
	for f in $(COMPONENTS); do $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	echo Done

fclean:
	echo Fully cleaning libft...
	for f in $(COMPONENTS); do $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR) $(NAME)
	echo REMOVED $(NAME)
	echo Done

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette | grep -v OK || echo "All good"

.PHONY: all clean fclean re norm
.SILENT:
