/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:55:29 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/04 10:49:12 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *s)
{
	unsigned int	i;
	long int		a;
	int				neg;

	i = 0;
	a = 0;
	neg = 0;
	while (ft_isspace(s[i]))
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
		i++;
	neg = i;
	while (ft_isdigit(s[i]))
	{
		a = (a * 10) + (s[i] - '0');
		i++;
	}
	if (s[neg - 1] == '-')
		a *= -1;
	return (a);
}
