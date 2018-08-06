/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 06:53:00 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/04 14:07:01 by kmarchan         ###   ########.fr       */
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

void	sort_a(t_che *che)
{
	while (!sort_che(che->la, ascending))
	{
		if (che->la->norm > che->la->next->norm)
		{
			swap_ab(che->la);
			SA;
		}
		else
		{
			rotate_ab(&che->la);
			RA;
		}
		// print_ab(che);
	}
}

int	back2a(t_che *che)
{
	int n;

	n = 3;
	// slen = ft_lstlen(che->la);
	while (ft_lstlen(che->lb) > 0)
	{
		if (che->lb->norm  <= n)
		{
			PB;
			push_ab(&che->lb, &che->la);
			RA;
			rotate_ab(&che->la);
			n++;
		}
		else
		{
			RA;
			rotate_ab(&che->lb);
			// RA;
			// ft_putendl_fd(CYN "ra" RESET, 2);
		}
	}
	return (1);
}

void	sort_thre(t_che *che)
{
	t_stack *tmp;
	tmp = che->la;
	if (che->la->next->norm < che->la->norm)
	{
		SA;
		swap_ab(che->la);
		// print_ab(che);
	}
	che->la = tmp;
	if (che->la->norm > che->la->next->next->norm)
	{
		RRA;
		revrot_ab(&che->la);	
		// la = tmp;
		// print_ab(che);
	}	
}

void rra3(t_che *che)
{
	int i;
	i = 0;
	while (i++ < 3)
	{
		RRA;
		revrot_ab(&che->la);
	}
}
void	sort(t_che *che, int llen)
{
	// while (!sort_che(che->la, ascending) || ft_lstlen(che->lb) > 0)
	// {
		while (ft_lstlen(che->la) >= 5)
		{
			get_chunk(che, llen);
			llen -= (llen / 5);
			// print_ab(che);
		}
		PB;
		while (che->la->norm != 3 )
		{
			RA;
			rotate_ab(&che->la);
		}
		push_ab(&che->la, &che->lb);
		// print_ab(che);
		sort_thre(che);
		// print_ab(che);
		// sort_a(che);
		llen = ft_lstlen(che->lb);
		// int in;
		// n = 3;
		// while (ft_lstlen(che->lb) > 1)
		// {
			back2a(che);
			// n++;
			llen -= 1;
			// print_ab(che);
		// }
		// rra3(che);
		// pirint_ab(che);
		//while (ft_lstlen(che->lb) >= 5)
	//	{
			//back2a(che, llen);
	//	}
	// }s
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
	sort(che, llen);
	return (1);
}
