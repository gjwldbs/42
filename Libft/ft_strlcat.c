/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:31:37 by jhur              #+#    #+#             */
/*   Updated: 2020/02/26 11:53:53 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t len_d;
    size_t len_s;
    size_t i;

    len_d = ft_strlen(dest);
    len_s = ft_strlen(src);
    i = 0;

    if(len_d >= size)
        return(len_s + size);
    while(len_d + i < size - 1)
    {
        dest[len_d + i] = src[i];
        i++;
    }
    dest[len_d + i] = '\0';
    return(len_d + len_s);
}