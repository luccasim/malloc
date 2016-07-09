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

static void		bloc_dump(t_bloc *bloc, int j)
{
	unsigned int	i;
	unsigned int	size;
	char			*addr;
	int				use;

	i = 0;
	size = (bloc->type == 'N') ? N : M;
	size = (bloc->type == 'L') ? bloc->size : size - BLOC_SIZE;
	use = (bloc->status == USED) ? 1 : 0;
	while (i++ < (int)BLOC_SIZE)
	{
		if (use)
			ft_printf("{y:1}[%c%d]{e}", bloc->type, j);
		else
			ft_printf("{d:1}[%c%d]{e}", bloc->type, j);
	}
	if (!use)
		return ;
	addr = (char *)(bloc + 1);
	i = 0;
	while (i < size)
		ft_printf("{w:1}[%c]{e}", addr[i++]);
}

static void		head_dump(t_head *head)
{
	t_bloc		*b;
	int			i;
	int			j;

	i = 0;
	b = (t_bloc *)(head + 1);
	while (i++ < (int)HEAD_SIZE)
		ft_printf("{b:1}[H]{e}");
	j = 1;
	while (b)
	{
		bloc_dump(b, j);
		j++;
		b = b->next;
	}
}

static void		head_info(t_head *head)
{
	ft_printf("%-20s:\t{w:1}%p{e}\n", "Header addr", head);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "Header Size", HEAD_SIZE);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "Header Page", head->size);
	ft_printf("%-20s:\t{w:1}%u{e}\n", "N Area libre", head->n);
	ft_printf("%-20s:\t{w:1}%u{e}\n", "M Area libre", head->m);
	ft_printf("%-20s:\t{w:1}%p{e}\n", "Next Header", head->next);
}

void			ft_head_dump(t_head *head)
{
	ft_printf("Memory Dump Information\n");
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
