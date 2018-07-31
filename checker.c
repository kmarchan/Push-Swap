/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/31 13:44:19 by kmarchan         ###   ########.fr       */
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
		ft_putnbr_fd(la->data, 2);
		ft_putchar_fd(' ', 2);
		la = la->next;
	}
	ft_putchar_fd('\n', 2);
	la = tmp;
	while (la->next != NULL)
	{
		ft_putnbr_fd(la->norm, 2);
		ft_putchar_fd(' ', 2);
		la = la->next;
	}
	ft_putchar_fd('\n', 2);
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
	// if (!args(argc, argv))
	// 	ERROR;
	if (!la)
	{
		ERROR;
		return (0);
	}
	if (!read_instruction(che))//args(argc, argv));
		ERROR; 
	return (0);
}