/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/28 11:02:30 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	print_list(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		ft_putnbr(lst->data);
		ft_putchar(' ');
		lst = lst->next;
	}
	ft_putchar('\n');
	lst = tmp;
	while (lst->next != NULL)
	{
		ft_putnbr(lst->norm);
		ft_putchar(' ');
		lst = lst->next;
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

void	set_norm(int *ar, size_t n, t_list *lst)
{
	t_list *tmp;
	size_t e;

	tmp = lst;
	while (lst->next != NULL)
	{
		e = 0;
		while (e < n)
		{
			if (ar[e] == lst->data)
			{
				lst->norm = e;
			}
			e++;
		}
		lst = lst->next;
	}
	lst = tmp;
}

int		normalise(t_list *lst, size_t n)
{
	t_list		*tmp;
	int			*ar;

	tmp = lst;
	ar = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (lst->next != NULL)
	{
		ar[n] = lst->data;
		n++;
		lst = lst->next;
	}
	if (!sort_int_tab(ar, n))
		return (0);
	lst = tmp;
	set_norm(ar, n, lst);
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

int		sort_argument(t_list *lst, char *str)
{
	char	**ar;
	int		e;
	t_list	*tmp;

	e = 0;
	tmp = lst;
	ar = ft_strsplit(str, ' ');
	while (ar[e] != NULL)
	{
		lst->next = ft_intlstnew(lst->data);
		lst->data = (ft_atoi(ar[e]));
		lst = lst->next;
		e++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	int		arg;
	int		nor;
	int		c;
	t_list	*tmp;

	if (argc > 1)
	{
		arg = 1;
		nor = argc;
		lst = (t_list *)malloc(sizeof(t_list));
		tmp = lst;
		if (argc > 1)
		{
			while (arg < argc)
			{
				if (!is_all_digit(argv[arg]))
					ERROR;
				if (ft_strstr(argv[arg], " "))
					sort_argument(lst, argv[arg]);
				else
					lst->next = ft_intlstnew(lst->data);
					lst->data = (ft_atoi(argv[arg]));
					lst = lst->next;
				arg++;
			}
			lst = tmp;
			c = normalise(lst, argc);
			if (c == 0)
				ERROR;
		}
		lst = tmp;
		print_list(lst);
	}
	return (0);
}
