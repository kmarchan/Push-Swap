/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:33:30 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/08 08:36:21 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <limits.h>

void	set_norm(int *ar, size_t n, t_che *che)
{
	t_stack	*tmp;
	size_t	e;

	tmp = che->la;
	while (che->la->next != NULL)
	{
		e = 0;
		while (e < n)
		{
			if (ar[e] == che->la->data)
			{
				che->la->norm = e;
			}
			e++;
		}
		che->la = che->la->next;
	}
	che->la = tmp;
}

int		normalise(t_che *che, size_t n)
{
	t_stack		*tmp;
	int			*ar;

	tmp = che->la;
	ar = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (che->la->next != NULL)
	{
		ar[n] = che->la->data;
		n++;
		che->la = che->la->next;
	}
	if (!sort_int_tab(ar, n))
	{
		return (0);
	}
	che->la = tmp;
	set_norm(ar, n, che);
	return (1);
}

int		sort_args(t_che *che, char *str)
{
	char	**ar;
	int		e;

	e = 0;
	ar = ft_split(str);
	while (ar[e] != NULL)
	{
		if (ft_atoi(ar[e]) < -217478368 || ft_atoi(ar[e]) > 217478367)
		{
			return (0);
		}
		che->la->next = ft_intlstnew();
		che->la->data = (ft_atoi(ar[e]));
		che->la = che->la->next;
		e++;
	}
	return (1);
}