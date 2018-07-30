#include "libft.h"
#include "checker.h"

void	set_norm(int *ar, size_t n, t_che *che)
{
	t_stack *tmp;
	size_t e;

	tmp = che->la;
	while (che->la->next != NULL)
	{
		e = 0;
		while (e < n)
		{
			if (ar[e] == che->la->data)
			{
				che->la->norm = e;
			}
			e++;
		}
		che->la = che->la->next;
	}
	che->la = tmp;
}

int		normalise(t_che *che, size_t n)
{
	t_stack		*tmp;
	int			*ar;

	tmp = che->la;
	ar = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (che->la->next != NULL)
	{
		ar[n] = che->la->data;
		n++;
		che->la = che->la->next;
	}
	if (!sort_int_tab(ar, n))
		return (0);
	che->la = tmp;
	set_norm(ar, n, che);
	return (1);
}

int		sort_args(t_che *che, char *str)
{
	char	**ar;
	int		e;

	e = 0;
	ar = ft_strsplit(str, ' ');
	while (ar[e] != NULL)
	{
		che->la->next = ft_intlstnew(che->la->data);
		che->la->data = (ft_atoi(ar[e]));
		che->la = che->la->next;
		e++;
	}
	return (1);
}

int		read_args(char *argv, t_che *che)
{
	if (!is_all_digit(argv))
		return (0);
	if (ft_strstr(argv, " "))
		sort_args(che, argv);
	else
	{
		che->la->next = ft_intlstnew(che->la->data);
		che->la->data = (ft_atoi(argv));
	}
	return (1);
}

int		args(int argc, char **argv, t_che *che)
{
	// t_stack	*la;
	int		arg;
	int		c;
	t_stack	*tmp;

	if (argc <= 1)
		return (0);
	arg = 1;
	che->la = (t_stack *)malloc(sizeof(t_stack));
	tmp = che->la;
	while (arg < argc)
	{
		if (!read_args(argv[arg], che))
			return (0);
		che->la = che->la->next;
		arg++;
	}
	che->la = tmp;
	c = normalise(che, argc);
	if (c == 0)
		return (0);
	return (1);
}
