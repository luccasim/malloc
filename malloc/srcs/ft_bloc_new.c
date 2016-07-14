/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bloc_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:37:46 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 15:14:26 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

t_bloc		*ft_bloc_new(void *addr, size_t size)
{
	t_bloc		*bloc;

	bloc = addr;
	bloc->type = (size == N) ? 'N' : 'M';
	bloc->status = FREE;
	bloc->size = 0;
	addr += size;
	bloc->next = addr;
	return (bloc);
}
