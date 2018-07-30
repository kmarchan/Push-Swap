
#include "libft.h"
#include "checker.h"
#include "get_next_line.h"

void	swap_ab(t_stack *l1)
{
	int temp;
	t_stack *tmp;
	(void)temp;
	tmp = l1;
	if (l1->next != NULL)
	{
		temp = l1->data;
		l1->data = l1->next->data;
		l1->next->data = temp;
	}
	l1 = tmp;
}

// void	rotate_ab(t_stack *lst)
// {
// 	t_stack *tmp;
// 	t_stack *pop;

// 	pop = lst;
// 	tmp = lst;
// 	pop->next = NULL;
// 	while (lst->next != NULL)
// 	{
// 		lst = lst->next;
// 	}
// 	lst->next = pop;
// 	lst = tmp;
// }

// // void		push_ab(t_stack *l1, t_stack *l2)
// // {
// // 	t_stack *t1;
// // 	t_stack *t2;

// // 	t1 = l1;
// // 	t2 = l2;
// // 	la = la->next;
// // }

void		read_instruction(t_che *che)
{
	// t_stack	*lb;
	int		fd;
	int		ret;
	char	*buf;

	fd = 0;
	ret = 1;
	// lb = (t_stack*)malloc(sizeof(t_stack));
	// while (ret > 0)
	// {
		ret = get_next_line(fd, &buf);
		if (strcmp(buf, "sa"))
			swap_ab(che->la);
		else
			return ;
// 		if (strcmp(buf, "sb"))
// 			swap_ab(lb);
// 		if (strcmp(buf, "ss"))
// 		{
// 			swap_ab(la);
// 			swap_ab(lb);
// 		}
	// }
// // 		if (strcmp(buf, "pa"))
// // 		if (strcmp(buf, "pb"))
// // 		if (strcmp(buf, "ra"))
// // 		if (strcmp(buf, "rb"))
// // 		if (strcmp(buf, "rr"))
// // 		if (strcmp(buf, "rra"))
// // 		if (strcmp(buf, "rrb"))
// // 		if (strcmp(buf, "rrr"))
}
