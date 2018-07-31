
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
	ft_putendl_fd(CYN "A" RESET, 2);
	if (l1 == NULL || l1->next == NULL)
		return (0);
	ft_putendl_fd(CYN "B" RESET, 2);
	if (ft_lstlen(l1) <= 1)
		return (0);
	ft_putendl_fd(CYN "C" RESET, 2);
	ft_swap(&l1->data, &l1->next->data);
	ft_putendl_fd(CYN "D" RESET, 2);
	ft_swap(&l1->norm, &l1->next->norm);
	return (1);
}

void	rotate_ab(t_stack *lst)
{
	t_stack *tmp;
	t_stack *pop;

	pop = lst;
	tmp = lst;
	pop->next = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = pop;
	lst = tmp;
}

// // void		push_ab(t_stack *l1, t_stack *l2)
// // {
// // 	t_stack *t1;
// // 	t_stack *t2;

// // 	t1 = l1;
// // 	t2 = l2;
// // 	la = la->next;
// // }

int		more_instructions(char *buf, t_che *che)
{
		// if (strcmp(buf, "pa"))
		// if (strcmp(buf, "pb"))

		if (strcmp(buf, "ra"))
			rotate_ab(che->la);
		// if (strcmp(buf, "rb"))
		// if (strcmp(buf, "rr"))

		// if (strcmp(buf, "rra"))
		// if (strcmp(buf, "rrb"))
		// if (strcmp(buf, "rrr"))
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

int		read_instruction(t_che *che)
{
	int		ret;
	int		e;
	char	*buf;

	print_stack(che->la);
	while ((ret = get_next_line(che->fd, &buf) > 0))
	{
		if (strchr(buf, 's'))
			e = ins_swap(buf, che);
		// else if (strchr(buf, 'p'))
			// more_instructions(buf, che);
		print_stack(che->la);
		// else
		// {
		// 	// ERROR;
		// 	ft_putendl_fd(CYN "SA" RESET, 2);
		// 	return (0);
		// }
	}
	return (1);
}

// ft_putendl_fd(CYN "SA" RESET, 2);
// 		free(buf);
