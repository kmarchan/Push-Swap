/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 07:06:30 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/04 14:06:55 by kmarchan         ###   ########.fr       */
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
