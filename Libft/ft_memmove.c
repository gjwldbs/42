/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:02:22 by jhur              #+#    #+#             */
/*   Updated: 2020/02/26 15:08:29 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *ptr_dst;
    const unsigned char *ptr_src;

    ptr_dst = (unsigned char *)dst;
    ptr_src = (unsigned char *)src;
    
    if(ptr_dst <= ptr_src)//if memory not overlapped
    {
        while(len--)
            *ptr_dst++ = *ptr_src;//copy like memcpy
    }
    else//memory overlapped
    {
        ptr_dst = ptr_dst + len - 1;//make enough space
        ptr_src = ptr_src + len - 1;
        while(len--)
            *ptr_dst-- = *ptr_src--;//copy from the last
    }
    return(dst);
}