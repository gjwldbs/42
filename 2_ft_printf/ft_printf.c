/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:51:21 by jhur              #+#    #+#             */
/*   Updated: 2020/05/12 19:14:40 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = 0;
	while (*format)
	{
		if (ft_strchr(format, '%'))
			result += ft_processing(&format, &ap);
		else
		{
			result += ft_puts(format);
			break ;
		}
	}
	va_end(ap);
	return (result);
}
