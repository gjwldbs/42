#include "libasm.h"

int main(void)
{
	char dest[50];
	char buf[10];
	int fd;
	char *a;
	char *b;
	char *c;

	printf("========ft_write=======\n");
	printf("ft_write_size is : %zu\n", ft_write(1, "hello\n", 6));
	printf("errno %d\n", errno);
	ft_write(3, "hello\n", 6);
	printf("errno %d\n", errno);
	printf("========ft_read=======\n");
	fd = open("test.txt", O_RDONLY);
	printf("ft_read_size is : %zu\n", ft_read(fd, buf, 5));
	buf[5] = '\n';
	buf[6] = '\0';
	ft_write(1, buf, 6);
	printf("errno %d\n", errno);
	fd = open("test2.txt", O_RDONLY);
	ft_read(fd, buf, -1);
	buf[5] = '\n';
	buf[6] = '\0';
	ft_write(1, buf, 6);
	printf("errno %d\n", errno);
	printf("========ft_strlen=======\n");
	printf("strlen is : %zu\n", ft_strlen("wow"));
	printf("strlen is : %zu\n", ft_strlen(""));
	printf("========ft_strcpy=======\n");
	printf("%s\n", ft_strcpy(dest, "licorne"));
	printf("%s\n", ft_strcpy(dest, "aaa"));
	printf("%s\n", ft_strcpy(dest, "aa"));
	printf("%s\n", ft_strcpy(dest, ""));
	printf("========ft_strcmp=======\n");
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("a", "b"));
	printf("%d\n", ft_strcmp("", "a"));
	printf("%d\n", ft_strcmp("aaaaa", "a"));
	printf("%d\n", ft_strcmp("a", "aaaaa"));
	printf("========ft_strdup=======\n");
	a = ft_strdup("hello");
	b = ft_strdup("strdup is done!");
	c = ft_strdup("");
	printf("%s\n", a);
	printf("%s\n", b);
	printf("%s\n", c);
	free(a);
	free(b);
	free(c);
	return (0);
}