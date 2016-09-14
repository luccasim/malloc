#include "malloc.h"
#include "libft.h"
#include "ft_random.h"

static void	nalloc(int size)
{
	void		*addr;
	static int i = 'A';

	i++;
	if (i > 'Z')
		i = 'A';
	addr = malloc(size);
    ft_memset(addr, i, size);
}

int		main(void)
{
	char 	*new;
	int		i = 0;

	nalloc(16408);
	show_alloc_mem_ex(MALLOC_DUMP);
	return (0);
}