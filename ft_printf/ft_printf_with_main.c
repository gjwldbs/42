/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:51:21 by jhur              #+#    #+#             */
/*   Updated: 2020/03/22 23:46:15 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_list
{
    int zero_flag;
    int left;
    int precision;//flag
    int p_len;
    int width;
}               t_list;
char    *ft_strchr(const char *str, int ch)
{
    while(*str)
    {
        if(*str == (char)ch)
            return((char *)str);
        str++;
    }
    if(ch == '\0')
        return((char *)str);
    return(NULL);
}
size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while(s[i])
        i++;
    return(i);
}
void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int    ft_puts(const char *str)
{
    int result;

    result = 0;
    while(*str)
    {
        ft_putchar(*str);
        str++;
        result++;
    }
    return(result);
}
void    ft_precision_puts(const char *str, int p_len)
{
    int i;

    i = 0;
    while(i < p_len)
    {
        ft_putchar(*str);
        str++;
        i++;
    }
}
int ft_hex_len(long long c)
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
    return(count);
}
void ft_print_hex(long long c, const char *format) //unsigne int c
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

void ft_putnbr(long long n)
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
int ft_atoi(const char *str)
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
    return(result * sign);
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
void    ft_left_zero(int width, int d_len, int zero_flag, int left)
{
    int i;

    i = 0;
    if(zero_flag == 1 && left == 0)
    {
        while(i < (width - d_len))
        {
            write(1, "0", 1);
            i++;
        }
    }
}
void    ft_left_blank(int width, int d_len, int zero_flag, int left)
{
    int i;

    i = 0;
    if(zero_flag == 0 && left == 0)
    {
        while(i < (width - d_len))
        {
            write(1, " ", 1);
            i++;
        }
    }
}
void    ft_right_blank(int width, int d_len, int left)
{
    int i;

    i = 0;
    if(left == 1)
    {
        while(i < (width - d_len))
        {
            write(1, " ", 1);
            i++;
        }
    }
}
int  c_conversion(va_list *ap, t_list info)
{
    int data;
    int d_len;

    data = va_arg(*ap, int);
    d_len = 1;
    ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    ft_putchar((char)data);
    ft_right_blank(info.width, d_len, info.left);
    if (info.width > 0)
        return(info.width);
    else
        return (1);
}
int percent_conversion(t_list info)
{
    int d_len;

    d_len = 1;
    ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    ft_putchar('%');
    ft_right_blank(info.width, d_len, info.left);
    if (info.width > 0)
        return(info.width);
    else
        return (1);
}
void    s_with_precision(t_list info, int d_len, char *str)
{
    info.zero_flag = 0;
    if(info.p_len < 0)
        ft_puts(str);
    else
    {
        if(info.p_len < d_len)
            ft_left_blank(info.width, info.p_len, info.zero_flag, info.left);
        else
            ft_left_blank(info.width, d_len, info.zero_flag, info.left);
        ft_precision_puts(str, info.p_len);
        if(info.p_len < d_len)
            ft_right_blank(info.width, info.p_len, info.left);
        else
            ft_right_blank(info.width, d_len, info.left);
    }
}
void    s_without_precision(t_list info, int d_len, char *str)
{
    ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    ft_puts(str);
    ft_right_blank(info.width, d_len, info.left);
}
int    s_conversion(va_list *ap, t_list info)
{
    char *str;
    int d_len;
    
    //str = va_arg(*ap, char *);
    if (!(str = va_arg(*ap, char*)))
      str = "(null)";
    d_len = ft_strlen(str);
    
    if (info.precision == 1)
        s_with_precision(info, d_len, str);
    else
        s_without_precision(info, d_len, str);
    if (info.precision == 1)
    {
        if (info.p_len < d_len)
            d_len = info.p_len;
    }
    if (info.width > d_len)
        return (info.width);
    else
        return (d_len);
}
int    p_conversion(va_list *ap, t_list info, const char *format)
{
    void *ptr;
    int d_len;
    
    ptr = va_arg(*ap, void *);
    d_len = 14;
    ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    write(1, "0x", 2);
    ft_print_hex((long long)ptr, format);
    ft_right_blank(info.width, d_len, info.left);
    if (info.width > 0)
        return(info.width);
    else
        return (14);
}
int    d_is_negative(t_list info, int d_len, int data)
{
    info.zero_flag = 0;
    data *= -1;
    d_len -= 1;
    if (info.p_len < d_len)
        ft_left_blank(info.width, d_len + 1, info.zero_flag, info.left);
    else
        ft_left_blank(info.width, info.p_len + 1, info.zero_flag, info.left);
    ft_putchar('-');
    ft_left_zero(info.p_len, d_len, 1, 0);
    ft_putnbr(data);
    if (info.p_len < d_len)
        ft_right_blank(info.width, d_len + 1, info.left);
    else
        ft_right_blank(info.width, info.p_len + 1, info.left);
    if(info.width > info.p_len && info.width > d_len)
        return(info.width);
    else
    {
        if(info.width < d_len && info.p_len < d_len)
            return(d_len + 1);
        else
            return(info.p_len + 1);
    }
}
int    d_is_positive(t_list info, int d_len, int data)
{
    info.zero_flag = 0;
    if (info.p_len < d_len)
        ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    else
        ft_left_blank(info.width, info.p_len, info.zero_flag, info.left);
    ft_left_zero(info.p_len, d_len, 1, 0);
    ft_putnbr(data);
    if (info.p_len < d_len)
        ft_right_blank(info.width, d_len, info.left);
    else
        ft_right_blank(info.width, info.p_len, info.left);
    if(d_len > info.p_len && d_len > info.width)
        return(d_len);
    else
    {
        if (info.p_len > info.width)
            return (info.p_len);
        else
            return (info.width); 
    }
}
int    d_without_precision(t_list info, int d_len, int data)
{
    ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    ft_left_zero(info.width, d_len, info.zero_flag, info.left);
    ft_putnbr(data);
    ft_right_blank(info.width, d_len, info.left);
    if (info.width > d_len)
        return (info.width);
    else
        return (d_len);
}
int    d_conversion(va_list *ap, t_list info)
{
    int data;
    int d_len;
    
    data = va_arg(*ap, int);
    d_len = ft_len((long long)data);
    if(data < 0)
    {
        if (info.precision == 1)
            return(d_is_negative(info, d_len, data));
        else
            return(d_without_precision(info, d_len, data));
    }
    else
    {
        if (info.precision == 1)
            return(d_is_positive(info, d_len, data));
        else
            return(d_without_precision(info, d_len, data));
    }    
}
int    u_conversion(va_list *ap, t_list info)
{
    unsigned int data;
    int d_len;
    
    data = va_arg(*ap, int);
    d_len = ft_len((long long)data);
    if (info.precision == 1)
        return(d_is_positive(info, d_len, data));
    else
        return(d_without_precision(info, d_len, data));
}
int    x_with_precision(t_list info, int d_len, int data, const char *format)
{
    info.zero_flag = 0;
    if (info.p_len < d_len)
        ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    else
        ft_left_blank(info.width, info.p_len, info.zero_flag, info.left);
    ft_left_zero(info.p_len, d_len, 1, 0);
    ft_print_hex(data, format);
    if (info.p_len < d_len)
        ft_right_blank(info.width, d_len, info.left);
    else
        ft_right_blank(info.width, info.p_len, info.left);
    if(d_len > info.p_len && d_len > info.width)
        return(d_len);
    else
    {
        if (info.p_len > info.width)
            return (info.p_len);
        else
            return (info.width); 
    }
}
int    x_without_precision(t_list info, int d_len, int data, const char *format)
{
    ft_left_blank(info.width, d_len, info.zero_flag, info.left);
    ft_left_zero(info.width, d_len, info.zero_flag, info.left);
    ft_print_hex(data, format);
    ft_right_blank(info.width, d_len, info.left);
    if (info.width > d_len)
        return (info.width);
    else
        return (d_len);
}
int    x_conversion(va_list *ap, t_list info, const char *format)
{
    unsigned int data;
    int d_len;

    data = va_arg(*ap, int);
    d_len = ft_hex_len((long long)data);
    if (info.precision == 1)
        return(x_with_precision(info, d_len, data, format));
    else
        return(x_without_precision(info, d_len, data, format));
}

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
void ft_has_width(t_list *info, const char **format, va_list *ap)
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
void ft_has_precision(t_list *info, char const **format, va_list *ap)
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
int    ft_has_spec(t_list info, const char **format, va_list *ap)
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

int ft_printf(const char *format, ...)
{   
    va_list ap;//현재 처리할 가변 인수 위치 가리키는 변수
    int result;
    
    va_start(ap, format);
    result = 0;
    while(*format)
    {
        if(ft_strchr(format, '%'))
            result += ft_processing(&format, &ap);
        else
        {
            result = ft_puts(format);
            break;
        }
    }
    va_end(ap);
    return (result);
}
int main(void)
{
    //int a = 123;
    //int *p = &a;
    char str[30] = "helloWorld";

    // ft_printf("%d", -20);
    // printf("\n");
    
    // ft_printf("%c\n", 'a');    // a: 문자
    // printf("\n");
    
    // ft_printf("%s\n", "Hello, world!");    // Hello, world!: 문자열
    // printf("\n");
    
    // ft_printf("%u\n", 20);
    // printf("\n");
    
    // printf("%u\n", 20);
    
    // ft_printf("%5.4x", 180);    // 16진수 소문자 출력이면 앞에 0x를 붙임
    //  printf("\n");
    // printf("%5x", 15);
    //   printf("\n");
    // printf("%5.4x\n", 180);
    // ft_printf("%5.4X\n", 180);    // 16진수 대문자 출력이면 앞에 0X를 붙임
    
    // printf("%13p\n", &a);
    // ft_printf("%13p\n", &a);
    // printf("%2s", str);
    // printf("\n");
    // ft_printf("%2s", str);
    // printf("\n");
    // printf("%.13s hi", str);  
    // printf("\n");
    // ft_printf("%12.11s", str );
    // printf("\n");
    // printf("%4.5s", str);
    // printf("\n");
    // ft_printf("%4.3s", str);
    // printf("\n");
    // printf("%12.13s", str);
    // printf("\n");
    // ft_printf("%12.13s", str);
    // printf("\n");
    // printf("%9.13s", str);
    // printf("\n");
    // ft_printf("%9.13s", str);
    // printf("\n");
    ft_printf("%11s", "HelloWorlds");
    ft_printf("%5s", "abcde");
    printf("\n");
    ft_printf("%9s", NULL);
    printf("\n");
    ft_printf("%10d", 1234567898);
//     printf("%*.s", -3, "hello");
//     ft_printf("%*.s", -3, "hello");
//     printf("\n");
//     printf("%.*s", -3, "hello");
//     printf("\n");
//     ft_printf("%.*s", -3, "hello");
//     printf("\n");
//     ft_printf("%011.12d", -2147483647);
//     printf("\n");
//     printf("%011.12d", -2147483647);
//     printf("\n");
//     ft_printf("%*.*d ji", 9 , 6, -1234);
//     printf("\n");
//     printf("%*.*d ji", 9, 6, -1234);
//     printf("\n");
//     ft_printf("%9d", -1234);
//     printf("\n");
//     printf("%9d\n", -1234);
//     printf("\n");
//     //ft_printf("%-013.7d", 1234);
//     // printf("\n");
//     //printf("%-013.7d\n", 1234);
//     // printf("%-3c hi\n", 'a');
//     // ft_printf("%-3c hi", 'a');
//     // printf("\n");
//     // printf("res : %d\n", ft_printf("hello %12.2X %s %u", 200, "hi", 5));
//     // printf("res : %d\n", printf("hello %12.2X %s %u", 200, "hi", 5));
//     // ft_printf("%5.6u\n", 1234);
//     // ft_printf("%6.5u\n", 1234);
//     // ft_printf("%3.2u\n", 1234);
//     // ft_printf("%2.3u\n", 1234);
//     // printf("res : %d\n", printf("%5%"));
//     // printf("res : %d\n", ft_printf("%5%"));
//     // printf("res : %d\n", printf("%1%"));
//     // printf("res : %d\n", ft_printf("%1%"));
//     // printf("res : %d\n", printf("%%"));
//     // printf("res : %d\n", ft_printf("%%"));
//     // printf("res : %d\n", printf("%-1%"));
//     // printf("res : %d\n", ft_printf("%-1%"));
//     // printf("res : %d\n", printf("%-5%"));
//     // printf("res : %d\n", ft_printf("%-5%"));
//     // printf("ddres : %d\n", printf("%.%"));
//     // printf("ddres : %d\n", ft_printf("%.%"));
//     // printf("res : %d\n", printf("%.5%"));
//     // printf("res : %d\n", ft_printf("%.5%"));
//     // printf("res : %d\n", printf("%3.5%"));
//     // printf("res : %d\n", ft_printf("%3.5%"));
//     printf("res : %d\n", printf("%09.6d", -1234));
//     printf("res : %d\n", ft_printf("%09.6d", -1234));
//     printf("res : %d\n", printf("%09.5d", -1234));
//     printf("res : %d\n", ft_printf("%09.5d", -1234));
//     printf("res : %d\n", printf("%-9.10d", -1234));
//     printf("res : %d\n", ft_printf("%-9.10d", -1234));
//     printf("res : %d\n", printf("%-6.9d", -1234));
//     printf("res : %d\n", ft_printf("%-6.9d", -1234));
//     printf("res : %d\n", printf("%-3.9d", -1234));
//     printf("res : %d\n", ft_printf("%-3.9d", -1234));

//     printf("res : %d\n", printf("%2.3d", -1234));
//     printf("res : %d\n", ft_printf("%2.3d", -1234));
//     printf("res : %d\n", printf("%3.2d", -1234));
//      printf("res : %d\n", ft_printf("%3.2d", -1234));
     
//     printf("res : %d\n", printf("%6.2d", -1234));
//     printf("res : %d\n", ft_printf("%6.2d", -1234));
//     printf("res : %d\n", printf("%5.2d", -1234));
//      printf("res : %d\n", ft_printf("%5.2d", -1234));
//      printf("res : %d\n", printf("%3.6d", -1234));
//      printf("res : %d\n", ft_printf("%3.6d", -1234));
}
