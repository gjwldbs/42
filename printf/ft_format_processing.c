/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:45:49 by jhur              #+#    #+#             */
/*   Updated: 2020/03/22 23:44:47 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_read_flag(t_list *info, const char **format)
{
    if(**format == '-')
    {
        (*info).left = 1;
        (*format)++;
    }
    if(**format == '0')
    {
        (*info).zero_flag = 1;//0이면 0으로 채우고 0이 없으면 공백으로 채우게
        (*format)++;
    }
}
void    ft_has_width(t_list *info, const char **format, va_list *ap)
{
    (*info).width = ft_atoi(*format); //info.width에 담고
    if(**format == '*')
    {
        (*info).width = va_arg(*ap, int);
        if((*info).width < 0)
        {
            (*info).width *= -1;
            (*info).left = 1;
        }
        (*format)++;
    }
    else
    {
        while(**format >= '0' && **format <= '9')
            (*format)++;   //다음으로 넘어갈수있도록 자리 땡겨줌
    }
}
void    ft_has_precision(t_list *info, char const **format, va_list *ap)
{
    if(**format == '.')
    {
        (*info).precision = 1;
        ++(*format);
        (*info).p_len = ft_atoi(*format);
        if(**format == '*')
        {
            (*info).p_len = va_arg(*ap, int);
            (*format)++;
        }
        else
        {
            while(**format >= '0' && **format <= '9')
                (*format)++; //이 다음 작업 printf 안에서 처리하도록 
        }  
    }
}
int     ft_has_spec(t_list info, const char **format, va_list *ap)
{
    int result;

    result = 0;
    if(**format == 'c')//하나의 문자
        result = c_conversion(ap, info);
    else if(**format == 's')
        result = s_conversion(ap, info);
    else if(**format == 'p')
        result = p_conversion(ap, info, *format);
    else if(**format == 'd' || **format == 'i')
        result = d_conversion(ap, info);
    else if(**format == 'u')
        result = u_conversion(ap, info);
    else if(**format == 'x')
        result = x_conversion(ap, info, *format);
    else if(**format == 'X')
        result = x_conversion(ap, info, *format);
    else if(**format == '%')
        result = percent_conversion(info);
    return (result);
}
int    ft_processing(const char **format, va_list *ap)
{
    t_list info;
    int result;
    int count;

    count = 0;
    result = 0;
    info.zero_flag = 0;
    info.left = 0;
    info.precision = 0;
    info.p_len = 0;
    info.width = 0;
    while((**format) != '%')
    {
        ft_putchar(**format);
        count++;
        (*format)++;
    }
    (*format)++;
    ft_read_flag(&info, format);
    ft_has_width(&info, format, ap);
    ft_has_precision(&info, format, ap);
    result = ft_has_spec(info, format, ap) + count;
    ++(*format);

    return (result);
}