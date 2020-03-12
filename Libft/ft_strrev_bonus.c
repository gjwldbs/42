/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:34:57 by jhur              #+#    #+#             */
/*   Updated: 2020/03/08 19:28:34 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(str);
	while (j > i)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return (str);
}