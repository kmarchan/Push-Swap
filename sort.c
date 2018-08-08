/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 09:02:40 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/08 13:32:57 by kmarchan         ###   ########.fr       */
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
		get_chunk(che, llen-1);
		llen = ft_lstlen(che->la);
		// llen -= (llen / 5);
	}
	while (che->la->norm != 3)
	{
		RA;
		rotate_ab(&che->la);
	}
	// print_ab(che);
	PB;
	push_ab(&che->la, &che->lb);
	sort_thre(che);
	back2a(che);
	rra3(che);
}
