/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:52:02 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 14:46:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

void	free(void *ptr)
{
	pthread_mutex_lock(ft_malloc_mutex());
	ft_free(ptr);
	pthread_mutex_unlock(ft_malloc_mutex());
}
