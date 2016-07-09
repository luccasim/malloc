/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:52:02 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 14:46:53 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static int		check_munmap(t_head *free)
{
	t_bloc	*bloc;
	t_head	*other;
	t_head	*tmp;

	bloc = (t_bloc *)free + 1;
	tmp = g_head;
	if (bloc->type == 'L' && bloc->status == FREE)
		return (ft_head_del(free));
	other = NULL;
	while (tmp)
	{
		bloc = (t_bloc *)tmp + 1;
		if (tmp->n <= N - 1)
			other = tmp;
		tmp = tmp->next;
	}
	if (other)
		return (ft_head_del(free));
	return (0);
}

void			ft_free(void *ptr)
{
	t_head	*head;
	t_bloc	*bloc;

	head = g_head;
	if (!ptr || !head)
		return ;
	while (head)
	{
		bloc = ft_head_find(head, ptr);
		if (bloc)
		{
			ft_bloc_unset(head, bloc);
			check_munmap(head);
			return ;
		}
		head = head->next;
	}
	return ;
}
