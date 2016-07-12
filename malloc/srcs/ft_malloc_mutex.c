#include "malloc_struct.h"

pthread_mutex_t		*ft_malloc_mutex(void)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;	
	return (&mutex);
}