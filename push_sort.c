/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:40:55 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/08 08:46:21 by kmarchan         ###   ########.fr       */
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

int		back2a(t_che *che)
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
