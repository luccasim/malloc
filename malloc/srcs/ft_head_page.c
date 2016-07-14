#include "malloc_struct.h"

void		ft_head_page(t_head *head)
{
	int		i;

	i = 0;
	while (head)
		{
			head = head->next;
			i++;
		}
	ft_printf("Number head :%d\n",i);
}
