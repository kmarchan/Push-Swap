/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 06:53:00 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/07 14:44:06 by kmarchan         ###   ########.fr       */
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
			PB;
			push_ab(&che->la, &che->lb);
		}
		else
		{
			RA;
			rotate_ab(&che->la);
		}
	}
	return (1);
}

int		find_hi(t_che *che)
{
	t_stack *tmp;
	int		ret;

	ret = 0;
	tmp = che->lb;
	while (che->lb)
	{
		if (che->lb->norm > ret)
		{
			ret = che->lb->norm;
		}
		che->lb = che->lb->next;
	}
	che->lb = tmp;
	return (ret);
}

int	back2a(t_che *che)
{
	int n;

	n = find_hi(che);
	while (ft_lstlen(che->lb) > 0)
	{
		if (che->lb->norm == n)
		{
			PA;
			push_ab(&che->lb, &che->la);
			n--;
		}
		else
		{
			RB;
			rotate_ab(&che->lb);
		}
	}
	return (1);
}

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
		// print_ab(che);
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
	// print_ab(che);
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
	// print_ab(che);
	sort(che, llen);
	print_ab(che);
	return (1);
}
