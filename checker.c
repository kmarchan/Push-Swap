/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:59:25 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/24 10:50:19 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		arg;
	t_list	*tmp;

	arg = 0;
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
	}
	while (lst->next != NULL)
	{
		ft_putnbr(lst->data);
		lst = lst->next;
	}
}
