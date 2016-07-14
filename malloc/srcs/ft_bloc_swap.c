#include "malloc_struct.h"

static int	swap_condition(t_bloc *a, t_bloc *b)
{
	if (a->type != b->type)
		return (0);
	if (a->type == 'L' || b->type == 'L')
		return (0);
	return (1);
}

static void	swap_addr(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	swap_bloc(char *a, char *b, int size)
{
	char	tmp;
	int	i;

	i = 0;
	while (i < size)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
		i++;
	}
}

void		ft_bloc_swap(t_bloc *a, t_bloc *b)
{
	void	*addr1;
	void	*addr2;
	int	size;

	if (!swap_condition(a, b))
		return ;
	addr1 = a + 1;
	addr2 = b + 1;
	size = (a->type == 'N') ? N - BLOC_SIZE : M - BLOC_SIZE;
	swap_bloc((char *)addr1, (char *)addr2, size);
	swap_addr(&addr1, &addr2);
}
