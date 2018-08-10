/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:43:40 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/10 13:05:30 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# define CYN "\x1B[36m"
# define RESET "\x1B[0m"

typedef struct		s_stack
{
	int				data;
	int				norm;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_check
{
	t_stack			*la;
	t_stack			*lb;
	char			**ar;
	int				fd;
	int				ll;
}					t_che;

# define ERROR ft_putendl_fd("Error", 2);
# define KO ft_putendl_fd("KO", 2);
# define OK ft_putendl_fd("OK", 2);
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

int					sort_args(t_che *che, char *str);
int					read_args(char *argv, t_che *che, int end);
int					args(int argc, char **argv, t_che *che);
int					normalise(t_che *che, size_t n);
void				set_norm(int *ar, size_t n, t_che *che);

int					read_instruction(t_che *stk);
int					swap_ab(t_stack *l1);
void				push_ab(t_stack **l1, t_stack **l2);
void				rotate_ab(t_stack **lst);
void				revrot_ab(t_stack **lst);

void				ft_intlstadd(t_stack **alst, t_stack *new);
int					ft_lstlen(t_stack *lst);
int					sort_int_tab(int *tab, size_t n);
int					is_all_digit(char *str);
t_stack				*ft_intlstnew(void);
void				del_extra(t_stack *lst);
void				free_stack(t_stack *stack);

void				print_stack(t_stack *lst);
void				print_ab(t_che *che);

t_stack				*sort_che(t_stack *lst, int (*cmp)(int, int));
int					ascending(int a, int b);

int					get_chunk(t_che *che, int llen);
int					find_hi(t_che *che);
int					back2a(t_che *che);
void				sort_thre(t_che *che);
void				rra3(t_che *che);
void				sort(t_che *che, int llen);
int					find_next(t_che *che, int len, int range);

char				**ft_strspliter(char *str, char c);
char				**ft_split(char *str);
void				free_ar(char **ar, int n);

#endif
