ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
LINK	=	libft_malloc.so
NAME 	=	libft_malloc_$(HOSTTYPE).so
TEST	=	libftmalloc.a
SRC 	=	$(shell find $(DSRC) -name '*.c' -type f)
DOBJ 	=	objs
DSRC 	=	srcs
LIB 	=	-L libft/ -lft 
INC 	=	-I includes/ -I libft/includes/
CC 		=	llvm-gcc
CFLAGS 	=	-Wall -Werror -Wextra $(INC)
SDIR	=	$(shell find $(DSRC) -type d)
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))
OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -shared -fPIC -o $(NAME) -lpthread $(OBJ) $(LIB)
	@ln -s $(NAME) $(LINK)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(DOBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME) $(LINK) $(TEST)
	@echo "\033[31;1m$(NAME) removes!\n$(LINK) removes!\n$(TEST) removes!\033[0m"

re: fclean all

.PHONY: re all clean fclean
