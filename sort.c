/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 09:02:40 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/09 14:42:34 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <strings.h>

void	sort_thre(t_che *che)
{
	while (!sort_che(che->la, ascending))
	{
		if (che->la->norm == 2)
		{
			RA;
			rotate_ab(&che->la);
		}
		else if (che->la->norm < che->la->next->norm)
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

int		find_5(t_che *che, int len, int smal)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = che->la;
	while (tmp)
	{
		if (tmp->norm <= smal)
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

void	sort_5(t_che *che)
{
	while (ft_lstlen(che->la) > 3)
	{
		if (find_next(che, ft_lstlen(che->la), 1) == 0)
		{
			while (che->la->norm > 1)
			{
				RA;
				rotate_ab(&che->la);
			}
			PB;
			push_ab(&che->la, &che->lb);
		}
		else
		{
			while (che->la->norm > 1)
			{
				RRA;
				revrot_ab(&che->la);
			}
			PB;
			push_ab(&che->la, &che->lb);
		}
	}
	sort_thre(che);
	back2a(che);
}

void	sort(t_che *che, int llen)
{
	if (ft_lstlen(che->la) == 5)
	{
		sort_5(che);
		exit(0);
	}
	while (ft_lstlen(che->la) >= 5)
	{
		get_chunk(che, llen - 1);
		llen = ft_lstlen(che->la);
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
