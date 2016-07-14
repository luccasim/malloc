/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:37:04 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 14:45:53 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

void	*malloc(size_t size)
{
	void	*addr;

	pthread_mutex_lock(ft_malloc_mutex());
	addr = ft_malloc(size);
	pthread_mutex_unlock(ft_malloc_mutex());
	return (addr);
}
