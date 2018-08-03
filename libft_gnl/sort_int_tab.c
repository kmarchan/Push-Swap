/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:05:26 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/02 08:33:43 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include <limits.h>
#include "libft.h"

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
