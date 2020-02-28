/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:39:10 by jhur              #+#    #+#             */
/*   Updated: 2020/02/26 15:08:15 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    unsigned char *ptr_dst;
    const unsigned char *ptr_src;
    size_t i;

    ptr_dst = (unsigned char *)dst;
    ptr_src = (unsigned char *)src;
    i = 0;
    while(i < n)
    {
        ptr_dst[i] = ptr_src[i];
        if(ptr_dst[i] == (unsigned char)c)
            return((void *)(dst + i + 1));
        i++;
    }
    return(NULL);
}