/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:16:30 by jhur              #+#    #+#             */
/*   Updated: 2020/05/06 16:50:14 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_isdigit(int c);
int				ft_putchar(char c);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
int				ft_tolower(int c);
char			*ft_str_tolower(char *str);
size_t			ft_strlen(const char *str);
int				ft_putsp(char *str, int precision);
char			*ft_u_itoa(unsigned int n);
char			*ft_utl_base(unsigned long long number, int base);

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_digit_flag(char c, t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);
int		ft_dot_flag(const char *str, int start, t_flags *flags, va_list args);
int	ft_isflag(int c);
int	ft_isconversion(int c);
int	ft_conversion(int c, t_flags flags, va_list args);
int			d_conversion(int i, t_flags flags);
int			c_conversion(char c, t_flags flags);
int			s_conversion(char *str, t_flags flags);
int			x_conversion(unsigned int number, int lowercase, t_flags flags);
int	percent_conversion(t_flags flags);
int			p_conversion(unsigned long long num, t_flags flags);
int			u_conversion(unsigned int number, t_flags flags);
int	ft_handle_width(int width, int minus, int zero);

int				ft_printf(const char *format, ...);

#endif
