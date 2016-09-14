/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_defragmentation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:45:22 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/20 03:45:25 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

int		ft_bloc_defragmentation(t_head *head, t_bloc *bloc)
{
	t_bloc		*tmp;
	int			i;

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
	ft_memset((bloc + 1), 0, M);
	return (1);
}
