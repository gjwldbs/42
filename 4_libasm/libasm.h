#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

ssize_t ft_read (int fd, void *buf, size_t nbytes);
size_t	ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s1);

#endif