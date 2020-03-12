/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:02:28 by jhur              #+#    #+#             */
/*   Updated: 2020/03/03 18:32:01 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ptr_s1;
    const unsigned char *ptr_s2;
    size_t i;

    ptr_s1 = (unsigned char *)s1;
    ptr_s2 = (unsigned char *)s2;
    i = 0;
    if(n == 0)
        return(0);
    while(*ptr_s1 && *ptr_s2 && i < (n - 1))
    {
        if(*ptr_s1 != *ptr_s2)
            return(*ptr_s1 - *ptr_s2);
        i++;
        ptr_s1++;
        ptr_s2++;
    }
    return((int)(*ptr_s1 - *ptr_s2));
}