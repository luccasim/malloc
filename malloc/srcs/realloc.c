/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:09:05 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 14:48:47 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

void	*realloc(void *ptr, size_t size)
{
	void	*addr;

	pthread_mutex_lock(ft_malloc_mutex());
	addr = ft_realloc(ptr, size);
	pthread_mutex_unlock(ft_malloc_mutex());
	return (addr);
}
