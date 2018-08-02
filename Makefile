# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/08/02 08:33:29 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= checker

all:	$(NAME)

lib: 
	make re -C ./libft_gnl/

INCLUDES= -I ./libft_gnl/includes

SRC= checker.c ft_list.c get_args.c get_instruction.c instructions.c

OBJ= $(SRC:.c=.o)

$(NAME): 
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
