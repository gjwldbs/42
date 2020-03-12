/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:15:02 by jhur              #+#    #+#             */
/*   Updated: 2020/03/08 19:25:12 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int i;
	int neg;
	char *tmp;

	i = 0;
	neg = 0;
	tmp = malloc(sizeof(char) * 12);
	if (tmp == NULL || nbr == 0)
		return ((nbr == 0) ? "0" : NULL);
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	while (nbr)
	{
		tmp[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}