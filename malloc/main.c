#include <stdlib.h>
#include "ft_printf.h"
#include "malloc.h"
#include "libft.h"
#include <time.h>

int main(void)
{
	char 	*str;
	time_t 	date;
	int		sec;

	ft_printf("{w:1:%s}\n","Hello world it's malloc");

	str = malloc(40);
	sec = time(NULL);
	ft_printf("{g:1:%hk}\n",sec);
	// ft_strcpy(str, "Bonjour"); 
	show_alloc_mem_ex(MALLOC_DUMP);
	return (0);
}