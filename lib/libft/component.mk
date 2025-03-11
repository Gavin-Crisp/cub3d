BUILD_DIR			:= $(BUILD_DIR)/$(NAME)
SRCS				:= $(addprefix $(NAME)/,$(SRCS))
OBJS				:= $(patsubst $(NAME)/$(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS				:= $(patsubst %.o,%.d,$(OBJS))

FINISHED			:= $(BUILD_DIR)/.finished_comp

export INDENT	:= $(shell echo $$(($(INDENT) + 1)))

define print
	a=0; while [ $$a -lt $(INDENT) ]; do echo -n $(INDENT_STYLE); a=`expr $$a + 1`; done; echo $1
endef

all: $(FINISHED)

$(FINISHED): $(OBJS)
	touch $(FINISHED)

$(BUILD_DIR)/%.o: $(NAME)/$(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(call print,CREATED $(@F))

-include $(DEPS)

clean:
	for f in $(OBJS); \
	do \
		if [ -f $$f ]; \
		then \
			rm $$f || continue; \
			$(call print,REMOVED $$(basename $$f)); \
		fi; \
	done
	rm -rf $(BUILD_DIR)

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re
.SILENT:
