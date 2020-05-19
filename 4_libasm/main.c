/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:38:56 by jhur              #+#    #+#             */
/*   Updated: 2020/05/19 15:33:02 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
size_t ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
int ft_strcmp(const char *s1, const char *s2);
int main()
{
	char *s = "hell";
	char *d = "hello";
	char *c = "";
	//printf("%zu\n", ft_strlen(s));
	//ft_strcpy(d, s);
	//printf("%s\n", d);

	//printf("%d\n", ft_strcmp(d, s));
	//printf("%d\n", strcmp(d, s));
	//printf("%d", strcmp(d, s));
	printf("%zd\n", ft_write(1, c, 4));
	printf("%zd", write(1, c, 4));
}