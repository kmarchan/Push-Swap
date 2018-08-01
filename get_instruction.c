
#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		swap_ab(t_stack *l1)
{
	if (l1 == NULL || l1->next == NULL)
		return (0);
	if (ft_lstlen(l1) <= 1)
		return (0);
	ft_swap(&l1->data, &l1->next->data);
	ft_swap(&l1->norm, &l1->next->norm);
	return (1);
}

void	rotate_ab(t_stack **lst)
{
	t_stack *tmp;
	t_stack *pop;

	if (ft_lstlen(*lst) <= 1)
		return ;
	pop = *lst;
	*lst = (*lst)->next;
	tmp = pop;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	pop->next = NULL;
	tmp->next = pop;
}

void	revrot_ab(t_stack **lst)
{
	t_stack *tmp;
	t_stack *pop;

	if (ft_lstlen(*lst) <= 1)
		return ;
	pop = *lst;
	tmp = *lst;
	while (pop->next->next != NULL)
	{
		pop = pop->next;
	}
	tmp = pop;
	pop = pop->next;
	tmp->next = NULL;
	pop->next = *lst;
	*lst = pop;
}

void		push_ab(t_stack *l1, t_stack *l2)
{
	t_stack *t1;
	t_stack *t2;

	(void)t1;
	(void)t2;
	t1 = l1;
	t2 = l2;
	l1 = l1->next;
}

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
	}	// ft_putendl_fd(CYN "A" RESET, 2);
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
	if (strcmp(buf, "pa") == 0)
		push_ab(che->la, che->la);
	// if (strcmp(buf, "pb"));
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
	print_stack(che->la);
	while ((ret = get_next_line(che->fd, &buf) > 0))
	{
		if (strchr(buf, 's'))
			e = ins_swap(buf, che);
		else if (strchr(buf, 'r'))
			e = ins_rot(buf, che);
		else if (strchr(buf, 'p'))
			e = ins_push(buf, che);
		if (e == 0)
			return (0);
		print_stack(che->la);
	}
	return (1);
}

// ft_putendl_fd(CYN "SA" RESET, 2);
// 		free(buf);
