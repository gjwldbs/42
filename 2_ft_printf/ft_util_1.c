/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:19:34 by jhur              #+#    #+#             */
/*   Updated: 2020/05/12 15:54:24 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_puts(const char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		result++;
	}
	return (result);
}

void	ft_precision_puts(const char *str, int p_len)
{
	int	i;

	i = 0;
	while (i < p_len && *str)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
}
