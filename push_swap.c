/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 06:53:00 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/03 07:26:02 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <strings.h>

int main(int argc, char **argv)
{
	int		la;
	t_che	*che;

	if (argc <= 1)
		return (0);
	che = (t_che *)ft_memalloc(sizeof(t_che));
	la = args(argc, argv, che);
	if (!la)
	{
		ERROR;
		return (0);
	}
	if (!read_instruction(che))
	{
		ERROR;
		return (0);
	}
	return (1);
}