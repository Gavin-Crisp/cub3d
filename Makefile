NAME			:= cub3D

LIBS			:= ft mlx_Linux Xext X11 m
LIBS_TARGET		:= lib/libft/libft.a lib/mlx_linux/libmlx_Linux.a
INCLUDES		:= include lib/libft/ lib/mlx_linux/

SRC_DIR			:= srcs
SRCS			:= $(addprefix $(SRC_DIR)/,main)
SRCS			+= $(addprefix $(SRC_DIR)/,map)
SRCS			+= $(addprefix $(SRC_DIR)/casting/,cast get_rays intersection structs)
SRCS			+= $(addprefix $(SRC_DIR)/debug/,boundary intsct map point)
SRCS			+= $(addprefix $(SRC_DIR)/events/,edata on_destroy on_keydown on_move)
SRCS			+= $(addprefix $(SRC_DIR)/mlx_util/,colour hvline_rect image put put_line to_pixel)
SRCS			+= $(addprefix $(SRC_DIR)/parser/,boolean bounds parser render_data)
SRCS			+= $(addprefix $(SRC_DIR)/render/,2d 3d rd)

SRCS			:= $(addsuffix .c,$(SRCS))

BUILD_DIR		:= .build
OBJS			:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS			:= $(patsubst %.o,%.d,$(OBJS))

export CC		:= cc
CFLAGS			:= -Wall -Werror -Wextra
CPPFLAGS		:= $(addprefix -I,$(INCLUDES)) -MMD -MP
LDFLAGS			:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS			:= $(addprefix -l,$(LIBS))

CFLAGS			+= -g

#CFLAGS			+= -fsanitize=address
#LDFLAGS			+= -fsanitize=address

export CFLAGS

MAKEFLAGS		+= --no-print-directory

export INDENT	:= 0

RUN_FILE		:= maps/basic.cub

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	echo CREATED $(@F)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo CREATED $(@F)

-include $(DEPS)

clean:
	$(MAKE) -C lib/libft clean
	for f in $(OBJS); \
	do \
		if [ -f $$f ]; \
		then \
			rm $$f && echo "REMOVED $$(basename $$f)"; \
		fi; \
	done
	rm -rf $(BUILD_DIR)

fclean:
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/mlx_linux clean
	for f in $(OBJS); \
	do \
		if [ -f $$f ]; \
		then \
			rm $$f && echo "REMOVED $$(basename $$f)"; \
		fi; \
	done
	rm -rf $(BUILD_DIR)
	if [ -f $(NAME) ]; \
	then \
		rm $(NAME) && echo "REMOVED $(NAME)"; \
	fi

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette srcs include lib/libft | grep -v OK || echo "All good"

run: $(NAME)
	./$(NAME) $(RUN_FILE)

debug: $(NAME)
	lldb $(NAME)

.PHONY: all fclean clean re norm debug
.SILENT:
