NAME		= philo
#CFLAGS		= -Wall -Werror -Wextra
CFLAGS = -Wall -Werror -Wextra -g3
CC			= cc
VPATH		= ./srcs/:./srcs/db:./srcs/mem_utils:./srcs/mutex:./srcs/sim

INC = -Iincludes/

SRC_FILES	=	main \
				db_init utils \
				cleans exits \
				mutex mutex_utils threads\
				sim_utils sim sleep monitoring\

OBJ	= $(addsuffix .o, $(SRC_FILES))

all:  $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -I/usr/include -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) -o $(NAME)

clean:
	rm -f ${OBJ} 

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re