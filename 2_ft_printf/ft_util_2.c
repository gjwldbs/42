/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:31:38 by jhur              #+#    #+#             */
/*   Updated: 2020/03/16 17:34:28 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         ft_hex_len(long long c)
{
    int count;
    
    count = 0;
    if (c >= 0 && c <= 15)
        count++;
    else
    {
        while(c)
        {
            c = c / 16;
            count++;
        }
    }
    return (count);
}
void        ft_print_hex(long long c, const char *format)
{
    if(c > 15)
    {
        ft_print_hex(c / 16, format);
        ft_print_hex(c % 16, format);
    }
    else if(c > 9 && c <= 15)
    {
        if(*format == 'x' || *format == 'p')
            c = c + 39;
        else if(*format == 'X')
            c = c + 7;
        ft_putchar(c + '0');
    }
    else
        ft_putchar(c + '0');
}
void        ft_putnbr(long long n)
{
    if(n < 0)
    {
        ft_putchar('-');
        n *= -1;
    }
    if(n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
        ft_putchar(n + '0');
}
int         ft_atoi(const char *str)
{
    int sign;
    int result;
    int i;

    i = 0;
    while((9 <= str[i] && str[i] <= 13) || str[i] == 32)
        i++;
    sign = 1;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    result = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
long long   ft_len(long long n)
{
    int     len;
    len = 0;
    if (n <= 0)
        ++len;
    while (n != 0)
    {
        n = n / 10;
        ++len;
    }
    return (len);
}