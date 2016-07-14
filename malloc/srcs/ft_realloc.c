/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:09:05 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 14:45:46 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static t_bloc		*realloc_head(t_head *head, t_bloc *bloc, size_t size)
{
	t_bloc	*new;
	t_head	*tmp;

	new = ft_head_request(head, size);
	if (!new)
	{
		tmp = ft_head_new(size);
		ft_head_add(head, tmp);
		new = ft_head_request(tmp, size);
		ft_bloc_cpy(bloc, new);
		ft_bloc_unset(head, bloc);
		if (bloc->type == 'L')
			ft_head_del(head);
		return (((new) ? new + 1 : NULL));
	}
	ft_bloc_cpy(bloc, new);
	ft_bloc_unset(head, bloc);
	return (new + 1);
}

static t_bloc		*check_realloc(t_head *head, t_bloc *bloc, size_t size)
{
	if (bloc->type != 'L')
	{
		if (size <= N - BLOC_SIZE)
			return (bloc + 1);
		else if (size <= M - BLOC_SIZE)
			return (realloc_head(head, bloc, size));
		else
			return (realloc_head(head, bloc, size));
	}
	else
	{
		if (size < head->size)
			return (bloc + 1);
		else
			return (realloc_head(head, bloc, size));
	}
}

void				*ft_realloc(void *ptr, size_t size)
{
	void	*new;
	t_bloc	*bloc;
	t_head	*head;

	new = NULL;
	if (!ptr)
		return (ft_malloc(size));
	if (size == 0)
		return (ptr);
	head = g_head;
	while (head)
	{
		bloc = ft_head_find(head, ptr);
		if (bloc)
		{
			new = check_realloc(head, bloc, size);
			return (new);
		}
		head = head->next;
	}
	return (new);
}
