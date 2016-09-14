/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:39:06 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 16:05:41 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static void		head_dump(t_head *head)
{
	t_bloc		*b;
	int			j;
	char		*str;

	b = (t_bloc *)(head + 1);
	j = 1;
	str = "{w:1}[Zone %i, Type : '%c' Size %i/%i At %hk]{e}\n";
	while (b)
	{
		if (b->status == USED)
		{
			ft_printf(str, j, b->type, b->size, b->area_size, b->timestamp);
			ft_bloc_dump(b);
			ft_printf(ENDL);
		}
		j++;
		b = b->next;
	}
}

/*
static void		head_dump(t_head *head)
{
	char			*b;
	unsigned int	i;

	b = (char *)head;
	i = 0;
	while (i < head->size)
	{
		ft_printf("[%c]", *b);
		b++;
		i++;
	}
}
*/
static void		head_info(t_head *head)
{
	ft_printf("%-20s:\t{w:1}%p{e}\n", "Header addr", head);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "Header Size", HEAD_SIZE);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "Header Page", head->size);
	ft_printf("%-20s:\t{w:1}%u{e}\n", "Area Available", head->n);
	ft_printf("%-20s:\t{w:1}%p{e}\n", "Next Header", head->next);
}

void			ft_head_dump(t_head *head)
{
	ft_printf("Memory Dump Informations:\n");
	if (head)
	{
		while (head)
		{
			head_info(head);
			head_dump(head);
			head = head->next;
			ft_printf("\n");
		}
	}
	else
		ft_printf("{r:1}No head {e}\n");
}
