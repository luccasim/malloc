/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:38:43 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 17:53:59 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"
#include <time.h>

void	ft_bloc_set(t_head *head, t_bloc *bloc, size_t size)
{
	unsigned char	n;
	unsigned char	m;

	if (bloc->type != 'L')
	{
		n = (bloc->type == 'N') ? 1 : 0;
		m = (bloc->type == 'M') ? 1 : 0;
		head->n -= n;
		head->m += m;
	}
	bloc->status = USED;
	bloc->size = size;
	bloc->timestamp = time(NULL);
	size = (bloc->type == 'N') ? N : M;
	size = (bloc->type == 'L') ? bloc->size : size;
	bloc->area_size = size;
}
