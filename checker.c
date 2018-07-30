/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/30 09:48:55 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	print_stack(t_stack *la)
{
	t_stack *tmp;

	tmp = la;
	while (la->next != NULL)
	{
		ft_putnbr(la->data);
		ft_putchar(' ');
		la = la->next;
	}
	ft_putchar('\n');
	la = tmp;
	while (la->next != NULL)
	{
		ft_putnbr(la->norm);
		ft_putchar(' ');
		la = la->next;
	}
	return ;
}

int		is_all_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_che	*che;
	che = (t_che *)ft_memalloc(sizeof(t_che));
	int		la;
	// la = (t_stack*)malloc(sizeof(t_stack));
	la = args(argc, argv, che);
	print_stack(che->la);
	// if (!args(argc, argv))
	// 	ERROR;
	if (!la)
		ERROR;
	read_instruction(che);//args(argc, argv));
	return (0);
}