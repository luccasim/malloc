/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:45:43 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/20 03:45:47 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

void	ft_bloc_dump(t_bloc *bloc)
{
	size_t	size;
	size_t	i;
	char	*tmp;

	size = bloc->area_size;
	i = BLOC_SIZE;
	tmp = (char *)bloc;
	while (i < size)
	{
		ft_printf("[%c]", tmp[i]);
		i++;
	}
}
