/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:20:14 by jhur              #+#    #+#             */
/*   Updated: 2020/02/27 14:36:43 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *ptr;
    size_t i;
    size_t s_len;

    if(!s)
        return(NULL);
    s_len = ft_strlen(s);
    if(s_len < start)
    {
        if(!(ptr = (char *)malloc(sizeof(char) * 1)))
            return(NULL);
        ptr[0] = '\0';
        return(ptr);
    }
    if(!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
        return(NULL);
    i = 0;
    while(i < len)
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr[i] = '\0';
    return(ptr);
}