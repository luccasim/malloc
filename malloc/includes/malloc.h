/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:36:23 by luccasim          #+#    #+#             */
/*   Updated: 2016/03/30 15:53:07 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define MALLOC_INFO	1
# define MALLOC_ALLOC	2
# define MALLOC_DUMP	4
# define MALLOC_PAGE	8
# define MALLOC_TEST	16
# include <sys/mman.h>
# include <stdlib.h>

void		show_alloc_mem_ex(int action);
void		show_alloc_mem();
void		*ft_realloc(void *ptr, size_t size);
void		*realloc(void *ptr, size_t size);
void		*ft_malloc(size_t size);
void		*malloc(size_t size);
void		ft_free(void *ptr);
void		free(void *ptr);

#endif
