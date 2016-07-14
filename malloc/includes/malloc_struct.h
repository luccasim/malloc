/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:05:29 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 17:56:21 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

# include "libft.h"
# include "ft_printf.h"
# include "malloc.h"
# include <unistd.h>
# include <pthread.h>

# define PROT_FLAGS	PROT_READ | PROT_WRITE
# define MAP_FLAGS	MAP_ANON | MAP_PRIVATE
# define MIN(X, Y) 	(((X) < (Y)) ? (X) : (Y))
# define USED		1
# define FREE		0
# define MARG		-10
# define AREA_SIZE	(getpagesize() / 4)
# define N			(AREA_SIZE + BLOC_SIZE)
# define M			(N * 4 - (BLOC_SIZE * 3))
# define NBR_ALLOC	((65 * 2) + 1)
# define SMALL		(NBR_ALLOC - 1)
# define TINY		SMALL * 4
# define BLOC_SIZE	sizeof(t_bloc)
# define HEAD_SIZE	sizeof(t_head)

typedef struct		s_bloc
{
	char			type;
	char			status;
	unsigned int	size;
	struct s_bloc	*next;
}					t_bloc;

typedef struct		s_head
{
	unsigned short	n;
	unsigned short	m;
	unsigned int	size;
	struct s_head	*next;
}					t_head;

t_head				*g_head;
// pthread_mutex_t		g_mutex = PTHREAD_COND_INITIALIZER;

pthread_mutex_t		*ft_malloc_mutex(void);

void				*ft_realloc(void *ptr, size_t size);
void				*ft_malloc(size_t size);
void				ft_free(void *ptr);

void				ft_bloc_set(t_head *head, t_bloc *bloc, size_t size);
void				ft_bloc_unset(t_head *head, t_bloc *bloc);
void				ft_bloc_swap(t_bloc *a, t_bloc *b);
void				ft_bloc_cpy(t_bloc *str, t_bloc *dst);
int					ft_bloc_create_small(t_head *head, t_bloc *bloc);
t_bloc				*ft_bloc_new(void *addr, size_t size);

int					ft_head_del(t_head *head);
int					ft_head_add(t_head *main, t_head *head);
t_bloc				*ft_head_request(t_head *head, size_t size);
t_bloc				*ft_head_find(t_head *head, void *addr);
t_head				*ft_head_new(size_t size);

void				ft_head_page(t_head *head);
void				ft_head_dump(t_head *head);

#endif
