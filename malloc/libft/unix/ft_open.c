#include "ft_unix.h"

int	ft_open(char *path, int flags)
{
	int	fd;

	fd = open(path, flags);
	if (fd < 0)
	{
		ft_error("open fail", 1);
		ft_perror(path);
		ft_exit(EXIT_FAILURE);
	}
	return (fd);
}
