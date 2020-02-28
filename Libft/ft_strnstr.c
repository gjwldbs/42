/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:11:18 by jhur              #+#    #+#             */
/*   Updated: 2020/02/28 12:46:49 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t pos;
    size_t i;

    if(*little == '\0')
        return((char *)big);
    pos = 0;
    while(big[pos] && pos < len)
        {
            if(big[pos] == little[0])
            {
                i = 1;
                while(*little && big[pos + i] == little[i] && (pos + i) < len)
                    i++;
                if(little[i] == '\0')
                    return((char *)&big[pos]);
            }
            pos++;
        }
    return(NULL);
}