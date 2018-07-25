/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/24 15:47:02 by kmarchan         ###   ########.fr       */
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
		lst = lst->next;
	}
}

void	normalise(t_list *lst)
{
	t_list *tmp;
	

	tmp = lst;
	while (lst->next != NULL)
	{
		
	}
	lst = tmp;
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		arg;
	int		nor;
	int		tm;
	t_list	*tmp;

	arg = 1;
	nor = argc;
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
		normalise(lst);
	}
}
