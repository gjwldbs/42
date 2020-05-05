/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:59:20 by jhur              #+#    #+#             */
/*   Updated: 2020/05/05 18:57:30 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
    int zero_flag;
    int left;
    int precision;
    int p_len;
    int width;
}               t_list;

//util_1
char        *ft_strchr(const char *str, int ch);
size_t      ft_strlen(const char *s);
void        ft_putchar(char c);
int         ft_puts(const char *str);
void        ft_precision_puts(const char *str, int p_len);
//util_2
int         ft_hex_len(long long c);
void        ft_print_hex(long long c, const char *format);
void        ft_putnbr(long long n);
int         ft_atoi(const char *str);
long long   ft_len(long long n);
//padding
void    ft_left_zero(int width, int d_len, int zero_flag, int left);
void    ft_left_blank(int width, int d_len, int zero_flag, int left);
void    ft_right_blank(int width, int d_len, int left);
//c,s,% conversion
int     c_conversion(va_list *ap, t_list info);
int     percent_conversion(t_list info);
void    s_with_precision(t_list info, int d_len, char *str);
void    s_without_precision(t_list info, int d_len, char *str);
int     s_conversion(va_list *ap, t_list info);
//p,d,i conversion
int     p_conversion(va_list *ap, t_list info, const char *format);
int     d_is_negative(t_list info, int d_len, int data);
int     d_is_positive(t_list info, int d_len, int data);
int     d_without_precision(t_list info, int d_len, int data);
int     d_conversion(va_list *ap, t_list info);
//u,x,X conversion
int     u_conversion(va_list *ap, t_list info);
int     x_with_precision(t_list info, int d_len, int data, const char *format);
int     x_without_precision(t_list info, int d_len, int data, const char *format);
int     x_conversion(va_list *ap, t_list info, const char *format);
//format processing
void    ft_read_flag(t_list *info, const char **format);
void    ft_has_width(t_list *info, const char **format, va_list *ap);
void    ft_has_precision(t_list *info, char const **format, va_list *ap);
int     ft_has_spec(t_list info, const char **format, va_list *ap);
int     ft_processing(const char **format, va_list *ap);

int     ft_printf(const char *format, ...);

#endif