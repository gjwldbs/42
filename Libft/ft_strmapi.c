/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:44:33 by jhur              #+#    #+#             */
/*   Updated: 2020/02/28 12:46:26 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *tab;
    unsigned int i;

    if(!(tab = malloc(ft_strlen(s) + 1)))
        return(NULL);
    i = 0;
    while(s[i])
    {
        tab[i] = f(i, s[i]);
        i++;
    }
    tab[i] = '\0';
    return(tab);
}