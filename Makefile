NAME			:= cub3D

LIBS			:= ft mlx_linux m
LIBS_TARGET		:= lib/libft/libft.a lib/mlx-linux/libmlx_linux.a
INCLUDES		:= include lib/mlx-linux lib/libft

SRC_DIR			:= srcs
SRCS			:= $(addprefix $(SRC_DIR)/,main.c)
SRCS			+= $(addprefix $(SRC_DIR)/casting/,boundary.c intersection.c ray.c point.c)
SRCS			+= $(addprefix $(SRC_DIR)/mlx_util/,colour.c put_pixel.c)

BUILD_DIR		:= build
OBJ_DIR			:= $(BUILD_DIR)/objs
OBJS			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEP_DIR			:= $(BUILD_DIR)/deps
DEPS			:=  $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRCS))

export CC		:= cc
export CFLAGS	:= -Wall -Werror -Wextra -g
CPPFLAGS		= $(addprefix -I,$(INCLUDES)) -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
export LDFLAGS	:= $(addprefix -L,$(dir $(LIBS_TARGET))) -fsanitize=address
export LDLIBS	:= $(addprefix -l,$(LIBS))

MAKEFLAGS		+= --no-print-directory

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	$(info CREATED $@)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	mkdir -p $(dir $(DEP_DIR)/$*.d)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $^ -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/mlx_linux clean
	rm -rf $(BUILD_DIR)
	echo Cleaned cub3D

fclean:
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/mlx_linux clean
	rm -rf $(BUILD_DIR) $(NAME)
	echo Fully cleaned cub3D

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette srcs include lib/libft | grep -v OK || echo No problems found

.PHONY: all fclean clean re norm update
#.SILENT:
