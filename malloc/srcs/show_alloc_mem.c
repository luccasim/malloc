/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:37:16 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/17 17:03:41 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static int	name_area(int status, t_bloc *bloc)
{
	if (status == 'N')
		ft_printf("TINY :");
	else if (status == 'M')
		ft_printf("SMALL :");
	else if (status == 'L')
		ft_printf("LARGE :");
	ft_printf(" %p\n", bloc);
	return (0);
}

static int	show_bloc(t_head *head, int status, int first)
{
	t_bloc	*b;
	void	*a;
	int		ret;

	b = (t_bloc *)(head + 1);
	ret = 0;
	while (b)
	{
		a = b + 1;
		if (first)
		{
			if (b->type == status && b->status == USED)
				first = name_area(status, b);
		}
		if (b->type == status && b->status == USED && !first)
		{
			ft_printf("%p - %p : %d octets\n", a, a + b->size, b->size);
			ret += b->size;
		}
		b = b->next;
	}
	return (ret);
}

static int	show_head(t_head *head, int status)
{
	t_head		*tmp;
	int			sum;
	int			first;

	tmp = head;
	first = 1;
	sum = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		sum += show_bloc(tmp, status, first);
		if (sum)
			first = 0;
		tmp = tmp->next;
	}
	return (sum);
}

void		show_alloc_mem(void)
{
	t_head	*head;
	int		i;
	int		status;
	int		total;

	head = g_head;
	i = 0;
	total = 0;
	while (i < 3)
	{
		status = 'N' - i;
		total += show_head(head, status);
		i++;
	}
	ft_printf("Total : %d octets\n", total);
}
