/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:29:54 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/09 16:39:07 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <limits.h>

int		read_args(char *argv, t_che *che, int end)
{
	t_stack *tmp;
	tmp = che->la;
	if (!is_all_digit(argv))
		return (0);
	else if (ft_strstr(argv, " "))
	{
		if (!sort_args(che, argv))
			return (0);
	}
	else
	{
		if (ft_atoi(argv) < -217478368 || ft_atoi(argv) > 217478367)
		{
			return (0);
		}
		if (end)
		{
			che->la->next = ft_intlstnew();
		}
		che->la->data = (ft_atoi(argv));
		che->la->norm = -2;
	}
	che->la = tmp;
	// print_ab(che);
	return (1);
}

int		args(int argc, char **argv, t_che *che)
{
	int		arg;
	int		c;
	t_stack	*tmp;

	(void)argv;
	if (argc <= 1)
		return (0);
	arg = 1;
	che->la = (t_stack *)malloc(sizeof(t_stack));
	tmp = che->la;
	while (arg < argc)
	{
		if (!read_args(argv[arg], che, (arg < argc - 1)))
			return (0);
		che->la = che->la->next;
		arg++;
	}
	// print_ab(che);
	che->la = tmp;
	c = normalise(che, argc);
	if (c == 0)
		return (0);
	// print_ab(che);
	// del_extra(che->la);
	return (1);
}
