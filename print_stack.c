/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:06:30 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/27 10:03:18 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <string.h>

void	print_stack(t_stack *la)
{
	t_stack *tmp;

	tmp = la;
	while (la != NULL)
	{
		ft_putnbr_fd(la->data, 2);
		ft_putchar_fd(' ', 2);
		la = la->next;
	}
	ft_putchar_fd('\n', 2);
	la = tmp;
	while (la != NULL)
	{
		ft_putnbr_fd(la->norm, 2);
		ft_putchar_fd(' ', 2);
		la = la->next;
	}
	ft_putchar_fd('\n', 2);
	return ;
}

void	print_ab(t_che *che)
{
	ft_putendl_fd(CYN "Stack A" RESET, 2);
	print_stack(che->la);
	ft_putendl_fd(CYN "Stack B" RESET, 2);
	print_stack(che->lb);
}

void	print_norm(t_che *che, t_stack *s)
{
	int		i;
	t_stack	*tmp;

	tmp = s;
	while (tmp)
	{
		i = 0;
		ft_putstr("         ");
		while (i <= tmp->norm)
		{
			ft_putstr("X");
			i++;
		}
		while (i <= che->llen)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	print_vis(t_che *che)
{
	ft_putstr(CYN);
	print_norm(che, che->la);
	ft_putstr(MAG);
	print_norm(che, che->lb);
	ft_putstr(RESET);
	usleep(10000);
}

void	print(t_che *che)
{
	int i;

	i = 100000;
	if (che->vis == 1)
	{
		if (che->llen == 0)
		{
			che->llen = ft_lstlen(che->la);
			while (i--)
				ft_putchar(' ');
		}
		ft_putstr(CLR);
		ft_putstr(WHT "\n\n\n");
		ft_putstr("        ___  _  _ ____ _  _    ____ _ _ _ ____ ___        ");
		ft_putendl(CYN "             STACK A is CYAN              ");
		ft_putstr("        |__] |  | [__  |__| __ [__  | | | |__| |__]       ");
		ft_putendl(MAG "             STACK B is MAGENTA");
		ft_putstr(BLU);
		ft_putendl("        |    |__| ___] |  |    ___] |_|_| |  | |         ");
		ft_putstr(RESET);
		print_vis(che);
	}
	else if (che->vis == 2)
		print_ab(che);
}
