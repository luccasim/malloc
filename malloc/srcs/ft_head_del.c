/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:10:36 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/21 20:10:40 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

int	ft_head_del(t_head *head)
{
	t_head	*first;
	t_head	*tmp;

	first = g_head;
	tmp = first;
	while (tmp)
	{
		if (tmp->next == head)
		{
			if (first->next == NULL)
				g_head = NULL;
			tmp->next = head->next;
			munmap(head, head->size);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
