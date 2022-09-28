 
-include linked_list/Makefile.mk
-include app/Makefile.mk


NAME_MODULE	= ex1
OBJ_DIR = build_$(NAME_MODULE)

CFLAGS	+=	$(OPTIMIZE_OPTION)	\
		$(WARNNING_OPTION)	\
		-Winline			\
		-pipe				\
		-g					\
		-Wall				\

.PHONY: clean
.PHONY: run


# rule to build project
all: create $(OBJ_DIR)/$(NAME_MODULE)
run: $(OBJ_DIR)/$(NAME_MODULE)
	./$(OBJ_DIR)/$(NAME_MODULE)
clean:
	@rm -rf $(OBJ_DIR)



# link file .o to execute file
$(OBJ_DIR)/$(NAME_MODULE): $(OBJ)
	@echo ---------- START LINK CPP PROJECT ----------
	@echo gcc -o $@ $^ $(CFLAGS) $(CFLAGS)
	@gcc -o $@ $^ $(CFLAGS)

# build each files .c to .o
$(OBJ_DIR)/%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS)

# create folder build
create:
	@mkdir -p $(OBJ_DIR)

debug: create
	@gcc -o $(OBJ_DIR)/debug linked_list/linked_list.c && ./$(OBJ_DIR)/debug

