/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:39:20 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 16:55:48 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static size_t	page_size(size_t size)
{
	size_t	psize;
	size_t	nbr;

	psize = getpagesize();
	nbr = size;
	if (size > M_AREA)
		nbr = psize * ((nbr / psize) + 1);
	else
		nbr = psize * NBR_ALLOC;
	return (nbr);
}

static int		fragmentation_bloc(t_head *head, size_t mem)
{
	t_bloc	*bloc;
	int		i;
	void	*addr;

	addr = head + 1;
	i = 0;
	while (mem >= N)
	{
		bloc = ft_bloc_new(addr);
		addr = bloc->next;
		mem -= N;
		++i;
	}
	bloc->next = NULL;
	return (i);
}

static t_head	*small_head(void *addr, size_t page)
{
	t_head		*new;
	size_t		i;

	i = page - HEAD_SIZE;
	new = addr;
	new->m = 0;
	new->size = page;
	new->next = NULL;
	new->n = fragmentation_bloc(new, i);
	return (new);
}

static t_head	*large_head(void *addr, size_t page)
{
	t_head	*new;
	t_bloc	*big;

	new = addr;
	new->n = 0;
	new->m = 0;
	new->size = page;
	new->next = NULL;
	big = (t_bloc*)(new + 1);
	big->type = 'L';
	big->status = FREE;
	big->next = NULL;
	return (new);
}

t_head			*ft_head_new(size_t size)
{
	t_head	*new;
	void	*addr;
	size_t	page;

	page = page_size(size);
	addr = mmap(NULL, page, PROT_FLAGS, MAP_FLAGS, -1, 0);
	if (!addr)
		return (NULL);
	if (size > M_AREA)
		new = large_head(addr, page);
	else
		new = small_head(addr, page);
	return (new);
}
