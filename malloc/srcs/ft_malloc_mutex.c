/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:45:55 by luccasim          #+#    #+#             */
/*   Updated: 2016/07/20 03:45:58 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

pthread_mutex_t		*ft_malloc_mutex(void)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	return (&mutex);
}
