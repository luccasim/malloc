#ifndef FT_UNIX_H
# define FT_UNIX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_open(char *path, int oflags);
int	ft_close(int fd);
void	ft_exit(int status);
void	ft_perror(char *str);
char	*ft_error(char *str, int act);

#endif
