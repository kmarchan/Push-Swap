#include "libft.h"
#include "checker.h"

void	set_norm(int *ar, size_t n, t_stack *la)
{
	t_stack *tmp;
	size_t e;

	tmp = la;
	while (la->next != NULL)
	{
		e = 0;
		while (e < n)
		{
			if (ar[e] == la->data)
			{
				la->norm = e;
			}
			e++;
		}
		la = la->next;
	}
	la = tmp;
}

int		normalise(t_stack *la, size_t n)
{
	t_stack		*tmp;
	int			*ar;

	tmp = la;
	ar = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (la->next != NULL)
	{
		ar[n] = la->data;
		n++;
		la = la->next;
	}
	if (!sort_int_tab(ar, n))
		return (0);
	la = tmp;
	set_norm(ar, n, la);
	return (1);
}

int		sort_args(t_stack *la, char *str)
{
	char	**ar;
	int		e;

	e = 0;
	ar = ft_strsplit(str, ' ');
	while (ar[e] != NULL)
	{
		la->next = ft_intlstnew(la->data);
		la->data = (ft_atoi(ar[e]));
		la = la->next;
		e++;
	}
	return (1);
}

int		read_args(char *argv, t_stack *la)
{
	if (!is_all_digit(argv))
		return (0);//ERROR;
	if (ft_strstr(argv, " "))
		sort_args(la, argv);
	else
	{
		la->next = ft_intlstnew(la->data);
		la->data = (ft_atoi(argv));
	}
	return (1);
	// la = la->next;
}	

int		args(int argc, char **argv)
{
	t_stack	*la;
	int		arg;
	int		c;

	t_stack	*tmp;
	if (argc > 1)
	{
		arg = 1;
		la = (t_stack *)malloc(sizeof(t_stack));
		tmp = la;
		while (arg < argc)
		{
			if (!read_args(argv[arg], la))
				return (0);
			la = la->next;
			arg++;
		}
		la = tmp;
		c = normalise(la, argc);
		if (c == 0)
			return (0);
	}
	return (1);
}
