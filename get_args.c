/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:29:54 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/26 15:31:05 by kmarchan         ###   ########.fr       */
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
			return (0);
		if (end)
			che->la->next = ft_intlstnew();
		che->la->data = (ft_atoi(argv));
		che->la->norm = -2;
	}
	che->la = tmp;
	return (1);
}

int		each_arg(int argc, char **argv, t_che *che)
{
	int arg;

	arg = 1;
	while (arg < argc)
	{
		if (ft_strcmp(argv[arg], "-v") == 0)
		{
			che->vis = 1;
			arg++;
		}
		if (ft_strcmp(argv[arg], "-s") == 0)
		{
			che->vis = 2;
			arg++;
		}
		if (!read_args(argv[arg], che, (arg < argc - 1)))
		{
			return (0);
		}
		che->la = che->la->next;
		arg++;
	}
	return (1);
}

int		args(int argc, char **argv, t_che *che)
{
	int		arg;
	int		c;
	t_stack	*tmp;

	c = 0;
	if (argc <= 1)
		return (0);
	arg = 1;
	che->la = ft_intlstnew();
	tmp = che->la;
	c = each_arg(argc, argv, che);
	che->la = tmp;
	if (c == 0)
	{
		free_stack(tmp);
		return (0);
	}
	c = normalise(che, argc);
	if (c == 0)
	{
		free_stack(tmp);
		return (0);
	}
	return (1);
}
