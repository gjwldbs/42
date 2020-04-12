/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:36:53 by jhur              #+#    #+#             */
/*   Updated: 2020/03/16 17:37:29 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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