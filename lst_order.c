/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:56:13 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/02 13:50:17 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ascending(int a, int b)
{
	return (a <= b);
}

t_stack	*sort_che(t_stack *lst, int (*cmp)(int, int))
{
	t_stack	*tmp;
	int		temp;

	temp = 0;
	tmp = lst;
	while (lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			return (0);
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
