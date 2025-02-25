NAME			:= cub3D

LIBS			:= ft mlx_Linux Xext X11 m
LIBS_TARGET		:= lib/libft/libft.a lib/mlx_linux/libmlx_Linux.a
INCLUDES		:= include lib/libft/ lib/mlx_linux/

SRC_DIR			:= srcs
SRCS			:= $(addprefix $(SRC_DIR)/,main.c)
SRCS			+= $(addprefix $(SRC_DIR)/casting/,boundary.c intersection.c ray.c point.c get_closest.c)
SRCS			+= $(addprefix $(SRC_DIR)/map/,cast.c map.c)
SRCS			+= $(addprefix $(SRC_DIR)/mlx_util/,colour.c image.c put.c put_line.c)
SRCS			+= $(addprefix $(SRC_DIR)/,render.c)

BUILD_DIR		:= .build
OBJS			:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS			:= $(patsubst %.o,%.d,$(OBJS))

export CC		:= cc
export CFLAGS	:= -Wall -Werror -Wextra -g
CPPFLAGS		:= $(addprefix -I,$(INCLUDES)) -MMD -MP
LDFLAGS			:= $(addprefix -L,$(dir $(LIBS_TARGET))) -fsanitize=address
LDLIBS			:= $(addprefix -l,$(LIBS))

MAKEFLAGS		+= --no-print-directory

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
	$(MAKE) -C lib/mlx_linux clean
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
	rm -fv $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette srcs include lib/libft | grep -v OK || echo "All good"

.PHONY: all fclean clean re norm update
.SILENT:
