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
	if (size > M)
		nbr = psize * ((nbr / psize) + 1);
	else
		nbr = psize * NBR_ALLOC;
	return (nbr);
}

static void		segmentation_bloc(t_head *head)
{
	t_bloc	*bloc;
	int		i;
	void	*addr;

	addr = head + 1;
	i = 0;
	while (i++ < head->n)
	{
		bloc = ft_bloc_new(addr, N);
		addr = bloc->next;
	}
	bloc->next = NULL;
}

static t_head	*small_head(void *addr, size_t page)
{
	t_head	*new;
	int		i;

	i = page - HEAD_SIZE;
	new = addr;
	new->n = i / N;
	new->m = 0;
	new->size = page;
	new->next = NULL;
	segmentation_bloc(new);
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
	big = (t_bloc*)new + 1;
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
	if (size > M)
		new = large_head(addr, page);
	else
		new = small_head(addr, page);
	return (new);
}
