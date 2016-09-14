#include "malloc.h"
#include "libft.h"
#include "ft_random.h"

static void	nalloc(int size)
{
	void		*addr;
	static int i = 'A';

	if (i > 'Z')
		i = 'A';
	addr = malloc(size);
    ft_memset(addr, i, size);
	i++;
}

int		main(void)
{
	char 	*new;
	int		i = 0;

	nalloc(164);
	nalloc(1024);
	nalloc(16407);
	nalloc(16408);
	nalloc(12124);
	show_alloc_mem_ex(MALLOC_DUMP);
	return (0);
}