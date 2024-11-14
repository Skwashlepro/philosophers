NAME		= philosophers
LIB			= includes/libft/libft.a
CFLAGS		= -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -g3
CC			= cc
VPATH		= ./srcs/:./srcs/db:./srcs/mem_utils:./srcs/mutex
LIBFT_PATH 	= ./includes/libft
INC = -Iincludes/

SRC_FILES	=	main \
				db_init utils \
				cleans exits \
				mutex mutex_utils \

OBJ	= $(addsuffix .o, $(SRC_FILES))

all: $(LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -I/usr/include -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) $(LIB) -o $(NAME)

$(LIB): 
	@make -s -C $(LIBFT_PATH)

clean:
	@make -s $@ -C $(LIBFT_PATH)
	rm -f ${OBJ} 

fclean: clean
	@make -s $@ -C $(LIBFT_PATH)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re