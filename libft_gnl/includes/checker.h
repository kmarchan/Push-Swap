/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:43:40 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/27 08:23:48 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef struct		s_list
{
	int				data;
	int				norm;
	struct s_list	*next;
}					t_list;

# define ERROR ft_putendl_fd("Error", 2);
# define SA ft_putendl_fd("sa", 1);
# define SB ft_putendl_fd("sb", 1);
# define SS ft_putendl_fd("ss", 1);
# define PA ft_putendl_fd("pa", 1);
# define PB ft_putendl_fd("pb", 1);
# define RA ft_putendl_fd("ra", 1);
# define RB ft_putendl_fd("rb", 1);
# define RR ft_putendl_fd("rr", 1);
# define RRA ft_putendl_fd("rra", 1);
# define RRB ft_putendl_fd("rrb", 1);
# define RRR ft_putendl_fd("rrr", 1);

void	ft_intlstadd(t_list **alst, t_list *new);
void	sort_int_tab(int *tab, size_t n);
t_list		*ft_intlstnew(int data);
int			acending(int a, int b);

#endif
