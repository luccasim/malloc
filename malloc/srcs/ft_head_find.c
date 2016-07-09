/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:10:54 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/21 20:14:46 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

t_bloc		*ft_head_find(t_head *head, void *addr)
{
	t_bloc	*bloc;

	if (!head || !addr)
		return (NULL);
	bloc = (t_bloc *)head + 1;
	addr -= BLOC_SIZE;
	while (bloc)
	{
		if (addr == bloc)
			return (bloc);
		bloc = bloc->next;
	}
	return (NULL);
}
