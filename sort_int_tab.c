/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:05:26 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/30 07:57:36 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "checker.h"
// void	ft_swap(int *a, int *b)
// {
// 	int temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

int		sort_int_tab(int *tab, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (tab[j + 1] == tab[j])
				return (0);
			if (tab[j + 1] < tab[j])
			{
				ft_swap(&tab[j + 1], &tab[j]);
			}
			j++;
		}
		i++;
	}
	return (1);
}
