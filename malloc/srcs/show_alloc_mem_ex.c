/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:37:23 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 15:31:46 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_struct.h"

static	void	malloc_info(void)
{
	ft_printf("{w:3}Malloc informations :{e}\n");
	ft_printf("%-20s:\t{w:1}%d{e}\n", "Struct Header size", HEAD_SIZE);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "Struct Bloc size", BLOC_SIZE);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "getpagesize()", getpagesize());
	ft_printf("%-20s:\t{w:1}%d{e}\n", "TINY Bloc size", N);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "SMALL Bloc size", M);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "MAX TINY bloc", TINY);
	ft_printf("%-20s:\t{w:1}%d{e}\n", "MAX SMALL bloc", SMALL);
}

void			show_alloc_mem_ex(int action)
{
	if (action & MALLOC_DUMP)
		ft_head_dump(g_head);
	if (action & MALLOC_INFO)
		malloc_info();
	if (action & MALLOC_ALLOC)
		show_alloc_mem();
	if (action & MALLOC_PAGE)
		ft_head_page(g_head);
}
