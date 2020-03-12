/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:01:55 by jhur              #+#    #+#             */
/*   Updated: 2020/03/03 20:52:47 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t len_s;
    size_t i;
    
    len_s = 0;
    while(src[len_s])
        ++len_s;
    i = 0;
    if(dstsize == 0)
        return(len_s);
    while(src[i] && i < (dstsize - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return(len_s);
}