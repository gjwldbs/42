/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:38:56 by jhur              #+#    #+#             */
/*   Updated: 2020/07/11 15:37:50 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
size_t ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s1);

int main()
{
	char *s = "hell";
	char *d = "hello";
	char *c = "";
	char *b;
	char *aa;
	char *bb;
	char *cc;
	//printf("%zu\n", ft_strlen(s));
	//ft_strcpy(d, s);
	//printf("%s\n", d);

	//printf("%d\n", ft_strcmp(d, s));
	//printf("%d\n", strcmp(d, s));
	//printf("%d", strcmp(d, s));
	//ft_write(1, s, 4);
	//printf("%zd\n", ft_write(1, c, 4));
	//printf("%d\n", errno);
	//printf("%zd\n", write(1, c, 4));
	//printf("%d\n", errno);
	//ft_write(1, s, 4);
	//write(1, s, 4);
	b = ft_strdup("hello");
	printf("%s\n", b);
}