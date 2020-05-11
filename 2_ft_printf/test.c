#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char a01[10];
	//char a02[10];
	//ft_printf("%05%");
	//printf("%.7s\n", "hello");
	//ft_printf("%.7s\n", "hello");
	//printf("%.2s%.7s\n", "hello"     , "world");
	//ft_printf("%.2s%.7s", "hello"     , "world");
	//printf("%05%");
	// printf("%.5s%7s\n", "yo", "boi");
	// ft_printf("%.5s%7s", "yo", "boi");
	printf("%d\n",ft_printf("%p", &a01));
	printf("%d\n",printf("%p", &a01));
	//printf("%p", NULL);
	//printf("%.0d", 0);
}