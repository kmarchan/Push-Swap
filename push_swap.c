/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 06:53:00 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/04 12:56:55 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <strings.h>

int		get_chunk(t_che *che, int llen)
{
	int slen;

	slen = ft_lstlen(che->lb);
	while (ft_lstlen(che->lb) - slen < llen / 5)
	{
		if (che->la->norm >= (llen - (llen / 5)))
		{
			push_ab(&che->la, &che->lb);
			PB;
		}
		else
		{
			rotate_ab(&che->la);
			RA;
		}
	}
	return (1);
}

void	print_ab(t_che *che)
{
	ft_putendl_fd(CYN "Stack A" RESET, 2);
	print_stack(che->la);
	ft_putendl_fd(CYN "\nStack B" RESET, 2);
	print_stack(che->lb);
	ft_putchar_fd('\n', 2);
}

void	sort(t_che *che, int llen)
{
	while (!sort_che(che->la, ascending) || ft_lstlen(che->lb) > 0)
	{
		while (ft_lstlen(che->la) >= 5)
		{
			get_chunk(che, llen);
			llen -= (llen / 5);
			print_ab(che);
		}
	}		
}

int	main(int argc, char **argv)
{
	int		la;
	int		llen;
	t_che	*che;

	if (argc <= 1)
		return (0);
	che = (t_che *)ft_memalloc(sizeof(t_che));
	la = args(argc, argv, che);
	if (!la)
	{
		ERROR;
		return (0);
	}
	llen = ft_lstlen(che->la);
	sort(che, llen);
	return (1);
}
