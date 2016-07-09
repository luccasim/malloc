/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_create_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:21:23 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 17:36:26 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

int		ft_bloc_create_small(t_head *head, t_bloc *bloc)
{
	t_bloc		*tmp;
	int		i;

	tmp = bloc;
	i = 0;
	while (i < 4)
	{
		if (tmp->status == USED)
			return (0);
		if (tmp->next == NULL && i < 3)
			return (0);
		tmp = tmp->next;
		i++;
	}
	bloc->type = 'M';
	head->n -= 4;
	head->m += 1;
	bloc->next = tmp;
	return (1);
}