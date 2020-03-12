/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:22:26 by jhur              #+#    #+#             */
/*   Updated: 2020/03/03 18:10:37 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s1)
{
    int i;
    int length;
    char *result;

    length = 0;
    while(s1[length])
        length++;
    result = (char *)malloc(sizeof(char) * (length + 1));
    i = 0;
    while(i < length)
    {
        result[i] = s1[i];
        i++;
    }
    result[i] = '\0';
    return(result);
}