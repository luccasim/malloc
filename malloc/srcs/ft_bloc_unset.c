/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:38:12 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/17 16:40:06 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

void		ft_bloc_unset(t_head *head, t_bloc *bloc)
{
	unsigned char	n;
	unsigned char	m;

	if (bloc->type != 'L')
	{
		n = (bloc->type == 'N') ? 1 : 0;
		m = (bloc->type == 'M') ? 1 : 0;
		if (bloc->type == 'M')
			ft_bloc_fragmentation(bloc);
		head->n += n;
		head->m += m;
	}
	bloc->status = FREE;
	bloc->size = 0;
	bloc->timestamp = 0;
}
