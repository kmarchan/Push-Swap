# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/08/04 11:42:34 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=	checker

NAME2=	push_swap

INCLUDES= -I ./libft_gnl/includes

all:	$(NAME1) $(NAME2)

lib: 
	make re -C ./libft_gnl/


SRC1=	checker.c ft_list.c get_args.c get_instruction.c instructions.c \
lst_order.c print_stack.c ft_split.c ft_strsplitter.c

SRC2=	push_swap.c ft_list.c get_args.c get_instruction.c instructions.c \
lst_order.c print_stack.c ft_split.c ft_strsplitter.c

OBJ1=	$(SRC1:.c=.o)

OBJ2=	$(SRC2:.c=.o)

$(NAME1):
	gcc -Wall -Werror -Wextra -c $(SRC1) $(INCLUDES)
	gcc -o $(NAME1) $(OBJ1) $(INCLUDES) -L. ./libft_gnl/libft.a

$(NAME2):
	gcc -Wall -Werror -Wextra -c $(SRC2) $(INCLUDES)
	gcc -o $(NAME2) $(OBJ2) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all
