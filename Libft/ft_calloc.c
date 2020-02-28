/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 10:03:58 by jhur              #+#    #+#             */
/*   Updated: 2020/02/26 10:38:39 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void *p;
    size_t ttl;

    ttl = count * size;
    if(!(p = malloc(ttl)))
        return(NULL);
    ft_memset(p, 0, ttl);
    return(p);
}