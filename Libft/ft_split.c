/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:50:10 by jhur              #+#    #+#             */
/*   Updated: 2020/04/06 13:29:45 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t  ft_wordcount(char const *s1, char const c)
{
    size_t  count;

    count = 0;
    while (*s1)
    {
        while (*s1 == c)
            s1++;
        if (*s1 && *s1 != c)
            count++;
        while (*s1 && *s1 != c)
            s1++;
    }
    return (count);
}

static size_t  ft_checklen(char const *s1, char const c)
{
    size_t  count;

    count = 0;
    while (*s1 && *s1 != c)
    {
        count++;
        s1++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    char    **result;
    size_t  i;
    size_t  j;

    result = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
    if (result == 0)
        return (0);
    i = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
        {   result[i] = malloc(sizeof(char) * (ft_checklen(s, c) + 1));
            if (result[i] == 0)
                return (0);
            j = 0;
            while (*s && *s != c)
                result[i][j++] = *s++;
            result[i][j] ='\0';
            i++;
        }
    }
    result[i] = '\0';
    return (result);
}