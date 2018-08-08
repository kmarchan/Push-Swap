/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:14:04 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/08 15:43:53 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

int		swap_ab(t_stack *l1)
{
	if (l1 == NULL || l1->next == NULL)
		return (0);
	if (ft_lstlen(l1) <= 1)
		return (0);
	ft_swap(&l1->data, &l1->next->data);
	ft_swap(&l1->norm, &l1->next->norm);
	return (1);
}

void	rotate_ab(t_stack **lst)
{
	t_stack *tmp;
	t_stack *pop;

	if (ft_lstlen(*lst) <= 1)
		return ;
	pop = *lst;
	*lst = (*lst)->next;
	tmp = pop;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	pop->next = NULL;
	tmp->next = pop;
}

void	revrot_ab(t_stack **lst)
{
	t_stack *tmp;
	t_stack *pop;
	if (ft_lstlen(*lst) <= 1)
		return ;
	pop = *lst;
	tmp = *lst;
	while (pop->next->next != NULL)
	{
		pop = pop->next;
	}
	tmp = pop;
	pop = pop->next;
	tmp->next = NULL;
	pop->next = *lst;
	*lst = pop;
}

void	push_ab(t_stack **l1, t_stack **l2)
{
	t_stack *t1;
	t_stack *t2;

	if (ft_lstlen(*l1) < 1)
		return ;
	t1 = *l1;
	t2 = t1;
	t2 = t2->next;
	t1->next = NULL;
	t1->next = *l2;
	*l2 = t1;
	*l1 = t2;
}
