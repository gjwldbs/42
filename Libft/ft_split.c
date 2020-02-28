/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:50:10 by jhur              #+#    #+#             */
/*   Updated: 2020/02/28 12:22:06 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      wdcnt(char *str, char c)
{
    int cnt;

    cnt = 0;
    while(*str)
    {
        if(*str == c)
        {
            ++cnt;
            while(*str && !(*str != c))
                ++str;
        }
        ++str;
    }
    return(cnt);
}
static void    ft_str_cpy(char *dst, char *from, char *until)
{
    while(from < until)
        *(dst++) = *(from++);
    *dst = 0;
}
char            **ft_split(char *str, char c)
{
    char **ret;
    int idx;
    char *from;
    
    ret = (char **)malloc(sizeof(char *) * wdcnt(str,c) + 1);
    idx = 0;
    while(*str)
    {
        if(*str != c)
        {
            from = str;
            while(*str && (*str != c))
                ++str;
            ret[idx] = (char *)malloc(str - from + 1);
            ft_str_cpy(ret[idx++], from, str);
        }
        ++str;
    }
    ret[idx] = 0;
    return(ret);
}