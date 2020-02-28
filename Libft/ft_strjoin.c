/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:50:49 by jhur              #+#    #+#             */
/*   Updated: 2020/02/27 10:18:23 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1;
    size_t len2;
    size_t i;
    char *ptr;

    if(!s1 || !s2)
        return(NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if(!(ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
        return(NULL);
    i = 0;
    while(s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    i = 0;
    while(s2[i])
    {
        ptr[len1] = s2[i];
        len1++;
        i++;
    }
    ptr[len1] = '\0';
    return(ptr);
}