/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:38:55 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 17:51:22 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static t_bloc	*find_large(t_head *head)
{
	t_bloc	*tmp;

	tmp = (t_bloc*)(head + 1);
	if (tmp->status == FREE)
		return (tmp);
	return (NULL);
}

static t_bloc	*find_small(t_head *head)
{
	t_bloc	*tmp;

	tmp = (t_bloc*)(head + 1);
	while (tmp)
	{
		if (tmp->status == FREE)
			if (ft_bloc_create_small(head, tmp))
				return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_bloc	*find_tiny(t_head *head)
{
	t_bloc	*tmp;

	tmp = (t_bloc*)(head + 1);
	while (tmp)
	{
		if (tmp->status == FREE)
				return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_bloc	*find_bloc(t_head *head, size_t size)
{
	if (size <= N - BLOC_SIZE)
		return (find_tiny(head));
	else if (size <= M - BLOC_SIZE)
		return (find_small(head));
	else if (size > M - BLOC_SIZE)
		return (find_large(head));
	else
		return (NULL);
}

t_bloc			*ft_head_request(t_head *head, size_t size)
{
	t_bloc	*request;

	request = NULL;
	if (!head)
		return (request);
	request = find_bloc(head, size);
	if (request)
		ft_bloc_set(head, request, size);
	return (request);
}
