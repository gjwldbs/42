/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:23:06 by jhur              #+#    #+#             */
/*   Updated: 2020/03/10 21:01:29 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;


    i = 0;
    if(n == 0)
        return(0);
    while(*s1 && *s2 && i < (n - 1))
    {
        if(*s1 != *s2)
            return((unsigned char)*s1 - *s2);
        i++;
        s1++;
        s2++;
    }
    return((unsigned char)*s1 - *s2);
}