# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/07/10 07:51:31 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= checker

all:	$(NAME)

LIB: 
	make re -C ./libft_gnl/

INCLUDES= -I ./libft_gnl/includes

SRC= checker.c ft_list.c sort_int_tab.c 

OBJ= $(SRC:.c=.o)

$(NAME): 
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
