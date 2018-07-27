/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:05:26 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/27 07:37:32 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// void	sort_int_tab(int *tab, size_t n)
// {
// 	unsigned int i;
// 	unsigned int j;

// 	i = 0;
// 	while (i < n)
// 	{
// 		j = 0;
// 		while (j < n - 1)
// 		{
// 		if (tab[j + 1] < tab[j])
// 			{
// 				// ft_swap(&tab[j + 1], &tab[j]);
// 				int temp;
// 				temp = tab[j+1];
// 				tab[j+1] = tab[j];
// 				tab[j] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void sort_int_tab(int *tab, unsigned int size)
{
    int    i;
    int temp;

    i = 0;
    temp = 0;
    while(i < (int)size)
    {
        if (i + 1 < (int)size && tab[i] > tab[i + 1])
        {
            temp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = temp;
            sort_int_tab(tab, size);
        }
        i++;
    }        
}