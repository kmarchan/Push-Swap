/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 06:53:00 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/10 14:05:29 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <strings.h>

int		main(int argc, char **argv)
{
	int		la;
	int		llen;
	t_che	*che;

	if (argc <= 1)
		return (0);
	che = (t_che *)ft_memalloc(sizeof(t_che));
	la = args(argc, argv, che);
	if (!la)
	{
		ERROR;
		if (che->ar)
			free_ar(che->ar, ft_lstlen(che->la));
		free(che);
		exit(0);
	}
	llen = ft_lstlen(che->la);
	if (llen >= 2 && llen <= 3)
	{
		sort_thre(che);
		if (che->ar)
			free_ar(che->ar, ft_lstlen(che->la));
		free_stack(che->la);
		free(che);
		exit(1);
	}
	if (sort_che(che->la, ascending))
		exit(0);
	sort(che, llen);
	if (che->ar)
		free_ar(che->ar, ft_lstlen(che->la));
	free_stack(che->la);
	free(che);
	exit(1);
}
