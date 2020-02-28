/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:19:20 by jhur              #+#    #+#             */
/*   Updated: 2020/02/27 20:43:24 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t len_s;
    char *ptr;

    len_s = ft_strlen(s1);
    if(!s1 || !set)
        return(NULL);
    while(*s1 && ft_strchr(set, *s1))
        s1++;
    while(len_s && ft_strchr(set, s1[len_s]))
        len_s--;
    ptr = ft_substr((char *)s1, 0, len_s + 1);
    return(ptr);
}
