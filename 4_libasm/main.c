/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:38:56 by jhur              #+#    #+#             */
/*   Updated: 2020/05/18 15:47:19 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
int main()
{
	char *s = "hello";
	printf("%zu\n", ft_strlen(s));
}