### FILES AND DIRECTORIES ###

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = includes/

LB_SRC = src/

OB_PATH = obj/

LB_FILES = get_next_line ft_lstadd_back_bonus ft_lstadd_front_bonus ft_lstdelone_bonus ft_lstiter_bonus ft_lstlast_bonus ft_lstmap_bonus ft_lstnew_bonus ft_lstsize_bonus ft_voidhex ft_unsigned ft_printf ft_hex ft_putchar ft_putnbr ft_putnbr_fd ft_putendl_fd ft_putstr_fd ft_putstr ft_putchar_fd ft_striteri ft_strmapi ft_itoa ft_split ft_strtrim ft_strlen ft_substr ft_strdup ft_calloc ft_strnstr ft_memcmp ft_memchr ft_strncmp ft_strrchr ft_strchr ft_tolower ft_toupper ft_strlcat ft_strlcpy ft_memmove ft_memcpy ft_atoi ft_isalnum ft_isascii ft_isprint ft_strjoin ft_bzero ft_isalpha ft_isdigit ft_memset

FILES_OBJ = $(addprefix $(OB_PATH), $(addsuffix .o, $(LB_FILES)))

#####################
### PROGRAM RULES ###
#####################

all: $(NAME)

$(NAME): $(FILES_OBJ)
	@ar -rsc $(NAME) $(FILES_OBJ)
	@echo "compiled $(NAME)"

$(OB_PATH)%.o: $(LB_SRC)%.c
	@mkdir -p $(OB_PATH)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

###################
### CLEAN RULES ###
###################

clean:
	@rm -rf $(OB_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all