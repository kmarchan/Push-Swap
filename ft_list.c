/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:48:10 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/26 18:01:05 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*ft_intlstnew(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
	{
		return (NULL);
	}
	if (!data)
	{
		new->data = 0;
		new->norm = 0;
	}
	new->next = NULL;
	return (new);
}

void		ft_intlstadd(t_stack **alst, t_stack *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

int			acending(int a, int b)
{
	return (a <= b);
}
