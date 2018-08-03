/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:36:56 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/03 11:40:41 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

int		ins_rot(char *buf, t_che *che)
{
	if (strcmp(buf, "ra") == 0)
		rotate_ab(&che->la);
	else if (strcmp(buf, "rb") == 0)
		rotate_ab(&che->lb);
	else if (strcmp(buf, "rr") == 0)
	{
		rotate_ab(&che->la);
		rotate_ab(&che->lb);
	}
	else if (strcmp(buf, "rra") == 0)
		revrot_ab(&che->la);
	else if (strcmp(buf, "rrb") == 0)
		revrot_ab(&che->lb);
	else if (strcmp(buf, "rrr") == 0)
	{
		revrot_ab(&che->la);
		revrot_ab(&che->lb);
	}
	else
		return (0);
	return (1);
}

int		ins_swap(char *buf, t_che *che)
{
	if (strcmp(buf, "sa") == 0)
		swap_ab(che->la);
	else if (strcmp(buf, "sb") == 0)
		swap_ab(che->lb);
	else if (strcmp(buf, "ss") == 0)
	{
		swap_ab(che->la);
		swap_ab(che->lb);
	}
	else
		return (0);
	return (1);
}

int		ins_push(char *buf, t_che *che)
{
	if (strcmp(buf, "pb") == 0)
	{
		push_ab(&che->la, &che->lb);
	}
	else if (strcmp(buf, "pa") == 0)
	{
		push_ab(&che->lb, &che->la);
	}
	else
		return (0);
	return (1);
}

int		read_instruction(t_che *che)
{
	int		ret;
	int		e;
	char	*buf;

	e = 0;
	while ((ret = get_next_line(che->fd, &buf) > 0))
	{
		if (strchr(buf, 's'))
			e = ins_swap(buf, che);
		else if (strchr(buf, 'r'))
			e = ins_rot(buf, che);
		else if (strchr(buf, 'p'))
			e = ins_push(buf, che);
		else
			return (0);
		if (e == 0)
			return (0);
		ft_putendl_fd(CYN "Stack A" RESET, 2);
		print_stack(che->la);
		ft_putendl_fd(CYN "\nStack B" RESET, 2);
		print_stack(che->lb);
		ft_putchar_fd('\n', 2);
	}
	return (1);
}

int		is_all_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
