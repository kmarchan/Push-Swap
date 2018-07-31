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

int			ft_lstlen(t_stack *lst)
{
	int		c;
	t_stack	*tmp;

	ft_putendl_fd(CYN "1" RESET, 2);
	c = 0;
	tmp = lst;
	ft_putendl_fd(CYN "2" RESET, 2);
	while (lst != NULL && lst->next != NULL)
	{
		c++;
		ft_putendl_fd(CYN "3" RESET, 2);
		lst = lst->next;
	}
	ft_putendl_fd(CYN "4" RESET, 2);
	lst = tmp;
	return (c);
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
