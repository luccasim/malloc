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

void	ft_bloc_defragmentation(t_bloc *bloc)
{
	t_bloc	*end;
	t_bloc	*tmp;
	void	*addr;

	if (bloc->type != 'M')
		return ;
	tmp = bloc;
	end = bloc->next;
	addr = (void *)(tmp);
	while (addr != end)
	{
		tmp = ft_bloc_new(addr, N);
		addr = tmp->next;
	}
}
