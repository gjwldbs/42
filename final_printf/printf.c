/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:14:58 by jhur              #+#    #+#             */
/*   Updated: 2020/05/06 16:51:03 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_width(int width, int minus, int zero)
{
	int count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}

static t_flags			ft_initialize(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.star = 0;
	flags.dot = -1;
	return (flags);
}

static int				ft_parsing(const char *str, int i,
t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isconversion(str[i]) && !ft_isflag(str[i])
		&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit_flag(str[i], *flags);
		if (ft_isconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int				ft_processing(const char *str, va_list args)
{
	t_flags	flags;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (!0)
	{
		flags = ft_initialize();
		if (!str[i])
			break ;
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parsing(str, ++i, &flags, args);
			if (ft_isconversion(str[i]))
				count += ft_conversion((char)flags.type, flags, args);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

int						ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	va_start(args, format);
	if (!(str = ft_strdup(format)))
		return (0);
	count += ft_processing(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
