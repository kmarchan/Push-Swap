/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 06:53:00 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/08 08:45:52 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <strings.h>

void	sort_thre(t_che *che)
{
	while (!sort_che(che->la, ascending))
	{
		if (che->la->norm < che->la->next->norm)
		{
			RRA;
			revrot_ab(&che->la);
		}
		else if (che->la->norm > che->la->next->norm)
		{
			SA;
			swap_ab(che->la);
		}
	}
}

void	rra3(t_che *che)
{
	while (!sort_che(che->la, ascending))
	{
		RRA;
		revrot_ab(&che->la);
	}
}

void	sort(t_che *che, int llen)
{
	while (ft_lstlen(che->la) >= 5)
	{
		get_chunk(che, llen);
		llen -= (llen / 5);
	}
	while (che->la->norm != 3)
	{
		RA;
		rotate_ab(&che->la);
	}
	PB;
	push_ab(&che->la, &che->lb);
	sort_thre(che);
	back2a(che);
	rra3(che);
}

int		main(int argc, char **argv)
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
	if (llen == 3)
	{
		sort_thre(che);
		return (1);
	}
	if (sort_che(che->la, ascending))
		return (0);
	sort(che, llen);
	print_ab(che);
	return (1);
}
