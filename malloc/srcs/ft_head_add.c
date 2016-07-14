/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:10:19 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/21 20:10:23 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

int	ft_head_add(t_head *main, t_head *new)
{
	t_head	*tmp;

	if (!main)
		return (0);
	tmp = main;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}
