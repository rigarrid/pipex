### FILES AND DIRECTORIES ###

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

LB_PATH = libft/

LB_LIB  = $(addprefix $(LB_PATH), libft.a)

PX_SRC = src/

OB_PATH = obj/

PX_FILES = pipex

FILES_OBJ = $(addprefix $(OB_PATH), $(addsuffix .o, $(PX_FILES)))

#####################
### PROGRAM RULES ###
#####################

all: $(NAME)

$(LB_LIB): $(LB_PATH)
	@mkdir -p $(OB_PATH)
	@make -C libft
	@cp libft/libft.a $(NAME).a

$(NAME): $(LB_LIB) $(FILES_OBJ)
	@ar -rsc $(NAME).a $(FILES_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(NAME).a
	@echo "compiled $(NAME)"

$(OB_PATH)%.o: $(PX_SRC)%.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	@echo "compiled object $@"

###################
### CLEAN RULES ###
###################

clean:
	@make clean -C libft
	@rm -rf $(OB_PATH)

fclean: clean
	@rm -rf libft/libft.a
	@rm -rf $(NAME).a
	@rm -rf $(NAME)

re: fclean all