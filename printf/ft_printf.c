/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 10:51:21 by jhur              #+#    #+#             */
/*   Updated: 2020/03/12 22:43:36 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

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
void    ft_puts(const char *str)
{
    while(*str)
    {
        ft_putchar(*str);
        str++;
    }
}
void    ft_precision_puts(const char *str, int precision_len)
{
    int i;

    i = 0;
    while(i < precision_len)
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
void    ft_left_zero(int width, int d_len, int zero_flag, int left_flag)
{
    int i;

    i = 0;
    if(zero_flag == 1 && left_flag == 0)
    {
        while(i < (width - d_len))
        {
            write(1, "0", 1);
            i++;
        }
    }
}
void    ft_left_blank(int width, int d_len, int zero_flag, int left_flag)
{
    int i;

    i = 0;
    if(zero_flag == 0 && left_flag == 0)
    {
        while(i < (width - d_len))
        {
            write(1, " ", 1);
            i++;
        }
    }
}
void    ft_right_blank(int width, int d_len, int left_flag)
{
    int i;

    i = 0;
    if(left_flag == 1)
    {
        while(i < (width - d_len))
        {
            write(1, " ", 1);
            i++;
        }
    }
}

int ft_printf(const char *format, ...)
{
    int data;//%c, %d에 사용할 변수
    char *str;//%s에 사용할 변수
    va_list ap;//현재 처리할 가변 인수 위치 가리키는 변수
    void *ptr;
    int d_len; //d_len data
    int zero_flag;
    int left_flag;
    int precision;//flag
    int precision_len;

    va_start(ap, format);

    while(*format)
    {
        zero_flag = 0;
        left_flag = 0;
        precision = 0;
        precision_len = 0;
        if(*format == '%')
        {
            int width = 0;
            format++;
            if(*format == '-')
            {
                left_flag = 1;
                format++;
            }
            if(*format == '0')
            {
                zero_flag = 1;//0이면 0으로 채우고 0이 없으면 공백으로 채우게
                format++;
            }
            width = ft_atoi(format); //width에 담고
            //
            if(*format == '*')
            {
                width = va_arg(ap, int);
                if(width < 0)
                {
                    width *= -1;
                    left_flag = 1;
                }
                format++;
            }
            else
            {
                // width = ft_atoi(format);
                while(*format >= '1' && *format <= '9')
                    format++;   //다음으로 넘어갈수있도록 자리 땡겨줌
            }
            //
            if(*format == '.')
            {
                precision = 1;
                ++format;
                precision_len = ft_atoi(format);
                if(*format == '*')
                {
                    precision_len = va_arg(ap, int);
                    format++;
                }
                else
                {
                    while(*format >= '0' && *format <= '9')
                        format++; //이 다음 작업 printf 안에서 처리하도록 
                }  
            }
            //
            if(*format == 'c')//하나의 문자
            {
                data = va_arg(ap, int);
                d_len = 1;
                ft_left_blank(width, d_len, zero_flag, left_flag);
                ft_putchar((char)data);
                ft_right_blank(width, d_len, left_flag);   
            }
            else if(*format == 's')
            {
                str = va_arg(ap, char *);
                d_len = ft_strlen(str);
                if (precision == 1)
                {
                    zero_flag = 0;
                    if(width < d_len)//precision_len < d_len
                     ft_left_blank(width, precision_len, zero_flag, left_flag);
                    else
                     ft_left_blank(width, d_len, zero_flag, left_flag);
                    ft_precision_puts(str, precision_len);
                    if(width < d_len)//precision_len < d_len
                     ft_right_blank(width, precision_len, left_flag);
                    else
                     ft_right_blank(width, d_len, left_flag);
                }
                else
                {
                    ft_left_blank(width, d_len, zero_flag, left_flag);
                    ft_puts(str);
                    ft_right_blank(width, d_len, left_flag);
                }
            }
            else if(*format == 'p')
            {
                ptr = va_arg(ap, void *);
                d_len = 14;
                ft_left_blank(width, d_len, zero_flag, left_flag);
                write(1, "0x", 2);
                ft_print_hex((long long)ptr, format);
                ft_right_blank(width, d_len, left_flag);
            }
            else if(*format == 'd' || *format == 'i')
            {
                data = va_arg(ap, int);
                d_len = ft_len((long long)data);
                if(data < 0)
                {
                    if (precision == 1)
                    {
                        zero_flag = 0;
                        data *= -1;
                        d_len -= 1;
                        if (precision_len < d_len)
                            ft_left_blank(width, d_len, zero_flag, left_flag);
                        else
                            ft_left_blank(width, precision_len + 1, zero_flag, left_flag);
                        ft_putchar('-');
                        ft_left_zero(precision_len, d_len, 1, 0);
                        ft_putnbr(data);
                        if (precision_len < d_len)
                            ft_right_blank(width, d_len, left_flag);
                        else
                            ft_right_blank(width, precision_len + 1, left_flag);
                    }
                    else
                    {
                        ft_left_blank(width, d_len, zero_flag, left_flag);
                        ft_left_zero(width, d_len, zero_flag, left_flag);
                        ft_putnbr(data);
                        ft_right_blank(width, d_len, left_flag);
                    }
                }
                else
                {
                    if (precision == 1)
                    {
                        zero_flag = 0;
                        if (precision_len < d_len)
                            ft_left_blank(width, d_len, zero_flag, left_flag);
                        else
                            ft_left_blank(width, precision_len, zero_flag, left_flag);
                        ft_left_zero(precision_len, d_len, 1, 0);
                        ft_putnbr(data);
                        if (precision_len < d_len)
                            ft_right_blank(width, d_len, left_flag);
                        else
                            ft_right_blank(width, precision_len, left_flag);
                    }
                    else
                    {
                        ft_left_blank(width, d_len, zero_flag, left_flag);
                        ft_left_zero(width, d_len, zero_flag, left_flag);
                        ft_putnbr(data);
                        ft_right_blank(width, d_len, left_flag);
                    }
                }
            }
            else if(*format == 'u')
            {
                unsigned int data = va_arg(ap, int);
                d_len = ft_len((long long)data);
                if (precision == 1)
                {
                    zero_flag = 0;
                    
                    if (precision_len < d_len)
                        ft_left_blank(width, d_len, zero_flag, left_flag);
                    else
                        ft_left_blank(width, precision_len, zero_flag, left_flag);
                    ft_left_zero(precision_len, d_len, 1, 0);
                    ft_putnbr(data);
                    if (precision_len < d_len)
                        ft_right_blank(width, d_len, left_flag);
                    else
                        ft_right_blank(width, precision_len, left_flag);
                }
                else
                {
                ft_left_blank(width, d_len, zero_flag, left_flag);
                ft_left_zero(width, d_len, zero_flag, left_flag);
                ft_putnbr(data);
                ft_right_blank(width, d_len, left_flag);
                }
            }
            else if(*format == 'x')
            {
                unsigned int data = va_arg(ap, int);
                d_len = ft_hex_len((long long)data);
                if (precision == 1)
                {
                    zero_flag = 0;
                    if (precision_len < d_len)
                        ft_left_blank(width, d_len, zero_flag, left_flag);
                    else
                        ft_left_blank(width, precision_len, zero_flag, left_flag);
                    ft_left_zero(precision_len, d_len, 1, 0);
                    ft_print_hex(data, format);
                    if (precision_len < d_len)
                        ft_right_blank(width, d_len, left_flag);
                    else
                        ft_right_blank(width, precision_len, left_flag);
                }
                else
                {
                    ft_left_blank(width, d_len, zero_flag, left_flag);
                    ft_left_zero(width, d_len, zero_flag, left_flag);
                    ft_print_hex(data, format);
                    ft_right_blank(width, d_len, left_flag);
                }
            }
            else if(*format == 'X')
            {
                unsigned int data = va_arg(ap, int);
                d_len = ft_hex_len((long long)data);
                if (precision == 1)
                {
                    zero_flag = 0;
                    
                    if (precision_len < d_len)
                        ft_left_blank(width, d_len, zero_flag, left_flag);
                    else
                        ft_left_blank(width, precision_len, zero_flag, left_flag);
                    ft_left_zero(precision_len, d_len, 1, 0);
                    ft_print_hex(data, format);
                    if (precision_len < d_len)
                        ft_right_blank(width, d_len, left_flag);
                    else
                        ft_right_blank(width, precision_len, left_flag);
                }
                else
                {
                    ft_left_blank(width, d_len, zero_flag, left_flag);
                    ft_left_zero(width, d_len, zero_flag, left_flag);
                    ft_print_hex(data, format);
                    ft_right_blank(width, d_len, left_flag);
                }
            }
            else if(*format == '%')
                ft_putchar('%');
            else
            {
                // if(*(format - 2) == '%')
                // ft_putchar('%');
                // write(1, format, 1);
            }
            ++format;
        }
        else
        {
            ft_puts(format);
            break;
        }
    }
    va_end(ap);
    return (0);
}
int main()
{
    int a = 123;
    int *p = &a;
    char str[30] = "helloWorld";

    // ft_printf("%d", -20);
    // printf("\n");
    
    // ft_printf("%c\n", 'a');    // a: 문자
    // printf("\n");
    
    // ft_printf("%s\n", "Hello, world!");    // Hello, world!: 문자열
    // printf("\n");
    
    // ft_printf("%u\n", -20);
    // printf("\n");
    
    // printf("%u\n", -20);
    
    // ft_printf("%5.4x", 180);    // 16진수 소문자 출력이면 앞에 0x를 붙임
    //  printf("\n");
    // printf("%5x", 15);
    // //  printf("\n");
    // printf("%5.4x\n", 180);
    // // //ft_printf("%X\n", 10);    // 16진수 대문자 출력이면 앞에 0X를 붙임
    
    // printf("%13p\n", &a);
    // ft_printf("%13p\n", &a);
    // printf("%2s", str);
    // printf("\n");
    // ft_printf("%2s", str);
    // printf("\n");
    // printf("%12.11s", str);
    // printf("\n");
    // ft_printf("%12.11s", str);
    // printf("\n");
    // printf("%4.3s", str);
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
    // printf("%12.s", str);
    // printf("\n");
    // ft_printf("%12.s", str);
    // printf("\n");

    ft_printf("%09.6d", 1234);
    printf("\n");
    ft_printf("%*d", 9 ,1234);
    printf("\n");
    ft_printf("%-*.*d ji", 9 , 6, -1234);
    printf("\n");
    printf("%-*.*d ji", 9, 6, -1234);
    printf("\n");
    ft_printf("%9d", -1234);
    printf("\n");
    printf("%9d\n", -1234);
    
    // printf("%-3c hi\n", 'a');
    // ft_printf("%-3c hi", 'a');
    // printf("\n");
}