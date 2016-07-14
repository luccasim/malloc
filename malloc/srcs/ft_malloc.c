/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:04:23 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/29 16:15:11 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static	void	*init_head(t_head *head, size_t size)
{
	t_bloc		*bloc;

	if (!head)
	{
		head = ft_head_new(size);
		g_head = head;
	}
	bloc = ft_head_request(head, size);
	return (((bloc) ? bloc + 1 : NULL));
}

static void		*seek_bloc(size_t size)
{
	t_head	*tmp;
	t_head	*last;
	t_bloc	*request;

	tmp = g_head;
	request = NULL;
	while (tmp)
	{
		request = ft_head_request(tmp, size);
		if (request)
			return (request + 1);
		if (tmp->next == NULL)
			last = tmp;
		tmp = tmp->next;
	}
	tmp = ft_head_new(size);
	last->next = tmp;
	request = ft_head_request(tmp, size);
	return (request + 1);
}

void			*ft_malloc(size_t size)
{
	void		*request;

	request = NULL;
	if (!g_head)
		request = init_head(NULL, size);
	else
		request = seek_bloc(size);
	return (request);
}
