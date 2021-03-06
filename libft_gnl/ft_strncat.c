/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:15:23 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/02 14:26:45 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s;

	s = 0;
	i = ft_strlen(s1);
	while (s2[s] != '\0' && s < n)
	{
		s1[i++] = s2[s++];
	}
	s1[i] = '\0';
	return (s1);
}
