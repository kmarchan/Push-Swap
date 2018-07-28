/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/27 08:24:06 by kmarchan         ###   ########.fr       */
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
}

int		check_int(char *in)
{
	int i;

	i = 0;
	while (in[i] != '\0')
	{
		if (!ft_isdigit(in[i]))
		{
			if (in[i] != '-' || in[i] != '+')
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

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

void	normalise(t_list *lst, size_t n)
{
	t_list		*tmp;
	int		*ar;

	tmp = lst;
	ar = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (lst->next != NULL)
	{
		ar[n] = lst->data;
		n++;
		lst = lst->next;
	}
	sort_int_tab(ar, n);
	lst = tmp;
	set_norm(ar, n, lst);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		arg;
	t_list	*tmp;

	arg = 1;
	lst = (t_list *)malloc(sizeof(t_list));
	tmp = lst;
	if (argc > 1)
	{
		while (arg < argc)
		{
			lst->next = ft_intlstnew(lst->data);
			lst->data = (ft_atoi(argv[arg]));
			lst = lst->next;
			arg++;
		}
		lst = tmp;
		normalise(lst, argc);
	}
	lst = tmp;
	print_list(lst);
}
