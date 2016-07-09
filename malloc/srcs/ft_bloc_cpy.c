/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:09:57 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/21 20:13:06 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static int	get_size(t_bloc *bloc)
{
	int	size;

	size = (bloc->type == 'N') ? N - BLOC_SIZE : M - BLOC_SIZE;
	size = (bloc->type == 'L') ? bloc->size : size;
	return (size);
}

void		ft_bloc_cpy(t_bloc *src, t_bloc *dst)
{
	int	size_src;
	int	size_dst;

	size_src = get_size(src);
	size_dst = get_size(dst);
	ft_memcpy(dst + 1, src + 1, MIN(size_src, size_dst));
}
