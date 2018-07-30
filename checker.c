/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/30 09:48:55 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	print_stack(t_stack *la)
{
	t_stack *tmp;

	tmp = la;
	while (la->next != NULL)
	{
		ft_putnbr(la->data);
		ft_putchar(' ');
		la = la->next;
	}
	ft_putchar('\n');
	la = tmp;
	while (la->next != NULL)
	{
		ft_putnbr(la->norm);
		ft_putchar(' ');
		la = la->next;
	}
	return ;
}

// int		check_int(char *in)
// {
// 	int i;

// 	i = 0;
// 	while (in[i] != '\0')
// 	{
// 		if (!ft_isdigit(in[i]))
// 		{
// 			if (in[i] != '-' || in[i] != '+')
// 			{
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void	set_norm(int *ar, size_t n, t_stack *la)
// {
// 	t_stack *tmp;
// 	size_t e;

// 	tmp = la;
// 	while (la->next != NULL)
// 	{
// 		e = 0;
// 		while (e < n)
// 		{
// 			if (ar[e] == la->data)
// 			{
// 				la->norm = e;
// 			}
// 			e++;
// 		}
// 		la = la->next;
// 	}
// 	la = tmp;
// }

// int		normalise(t_stack *la, size_t n)
// {
// 	t_stack		*tmp;
// 	int			*ar;

// 	tmp = la;
// 	ar = (int*)malloc(sizeof(int) * n + 1);
// 	n = 0;
// 	while (la->next != NULL)
// 	{
// 		ar[n] = la->data;
// 		n++;
// 		la = la->next;
// 	}
// 	if (!sort_int_tab(ar, n))
// 		return (0);
// 	la = tmp;
// 	set_norm(ar, n, la);
// 	return (1);
// }

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

// int		sort_args(t_stack *la, char *str)
// {
// 	char	**ar;
// 	int		e;

// 	e = 0;
// 	ar = ft_strsplit(str, ' ');
// 	while (ar[e] != NULL)
// 	{
// 		la->next = ft_intlanew(la->data);
// 		la->data = (ft_atoi(ar[e]));
// 		la = la->next;
// 		e++;
// 	}
// 	return (1);
// }

// int		read_args(char *argv, t_stack *la)
// {
// 	if (!is_all_digit(argv))
// 		return (0);//ERROR;
// 	if (ft_strstr(argv, " "))
// 		sort_args(la, argv);
// 	else
// 	{
// 		la->next = ft_intlanew(la->data);
// 		la->data = (ft_atoi(argv));
// 	}
// 	return (1);
// 	// la = la->next;
// }	

// int		args(int argc, char **argv)
// {
// 	t_stack	*la;
// 	int		arg;
// 	int		c;

// 	t_stack	*tmp;
// 	if (argc > 1)
// 	{
// 		arg = 1;
// 		la = (t_stack *)malloc(sizeof(t_stack));
// 		tmp = la;
// 		while (arg < argc)
// 		{
// 			if (!read_args(argv[arg], la))
// 				return (0);
// 			la = la->next;
// 			arg++;
// 		}
// 		la = tmp;
// 		c = normalise(la, argc);
// 		if (c == 0)
// 			return (0);
// 	}
// 	return (1);
// }

int main(int argc, char **argv)
{
	t_che	*che;
	che = (t_che *)ft_memalloc(sizeof(t_che));
	// t_stack *la;
	// la = (t_stack*)malloc(sizeof(t_stack));
	// la = args(argc, argv);
	if (!args(argc, argv))
		ERROR;
	// if (!la->data)
	// 	ERROR;
	read_instruction(che);//args(argc, argv));
	return (0);
}