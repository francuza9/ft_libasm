#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern size_t ft_write(int fd, const void *buf, size_t count);
extern char *ft_strdup(const char *s);

void	test_strlen()
{
	printf("---- ft_strlen -----\n");
	printf("\n------ Test 1 ------\n");
	printf("String --> 'Hello World!'\n");
	printf("strlen: %lu\n", strlen("Hello World!"));
	printf("ft_strlen: %lu\n", ft_strlen("Hello World!"));
	printf("\n------ Test 2 ------\n");
	printf("String --> ''\n");
	printf("strlen: %lu\n", strlen(""));
	printf("ft_strlen: %lu\n", ft_strlen(""));
}

void	test_strcpy()
{
	printf("\n\n------ ft_strcpy ------\n");
	char dest[10] = "Hello";
	printf("\n------ Test 1 ------\n");
	printf("Source --> 'World!'\n");
	printf("strcpy: %s\n", strcpy(dest, "World!"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "World!"));
	printf("\n------ Test 2 ------\n");
	printf("Source --> ''\n");
	printf("strcpy: %s\n", strcpy(dest, ""));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, ""));
	printf("\n------ Test 3 ------\n");
	printf("Source --> '0123456789a'\n");
	printf("strcpy: %s\n", strcpy(dest, "0123456789a"));
	printf("ft_strcpy: %s\n", ft_strcpy(dest, "0123456789a"));
}

void	test_strcmp()
{
	printf("\n\n------ ft_strcmp ------\n");
	printf("\n------ Test 1 ------\n");
	printf("String 1 --> 'Hello World!'\n");
	printf("String 2 --> 'Hello World!'\n");
	printf("strcmp: %d\n", strcmp("Hello World!", "Hello World!"));
	printf("ft_strcmp: %d\n", ft_strcmp("Hello World!", "Hello World!"));
	printf("\n------ Test 2 ------\n");
	printf("String 1 --> 'Hello World!'\n");
	printf("String 2 --> 'Hello Wo'\n");
	printf("strcmp: %d\n", strcmp("Hello World!", "Hello Wo"));
	printf("ft_strcmp: %d\n", ft_strcmp("Hello World!", "Hello Wo"));
	printf("\n------ Test 3 ------\n");
	printf("String 1 --> 'Hello World'\n");
	printf("String 2 --> 'Hello World!'\n");
	printf("strcmp: %d\n", strcmp("Hello World", "Hello World!"));
	printf("ft_strcmp: %d\n", ft_strcmp("Hello World", "Hello World!"));
	printf("\n------ Test 4 ------\n");
	printf("String 1 --> 'Hello World!'\n");
	printf("String 2 --> ''\n");
	printf("strcmp: %d\n", strcmp("Hello World!", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("Hello World!", ""));
	printf("\n------ Test 5 ------\n");
	printf("String 1 --> ''\n");
	printf("String 2 --> ''\n");
	printf("strcmp: %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("\n------ Test 6 ------\n");
	printf("String 1 --> '12345'\n");
	printf("String 2 --> '12354'\n");
	printf("strcmp: %d\n", strcmp("12345", "12354"));
	printf("ft_strcmp: %d\n", ft_strcmp("12345", "12354"));
	printf("\n------ Test 7 ------\n");
	printf("String 1 --> '12354'\n");
	printf("String 2 --> '12345'\n");
	printf("strcmp: %d\n", strcmp("12354", "12345"));
	printf("ft_strcmp: %d\n", ft_strcmp("12354", "12345"));
}

void	test_write()
{
	printf("\n\n------ ft_write ------\n");
	printf("\n------ Test 1 ------\n");
	printf("String --> 'Hello World!'\n");
	printf("write: %lu\n", write(1, "Hello World!", 12));
	printf("ft_write: %lu\n", ft_write(1, "Hello World!", 12));
	printf("\n------ Test 2 ------\n");
	printf("String --> ''\n");
	printf("write: %lu\n", write(1, "", 0));
	printf("ft_write: %lu\n", ft_write(1, "", 0));
	printf("\n------ Test 3 ------\n");
	printf("String --> NULL\n");
	printf("write: %lu\n", write(1, NULL, 1));
	printf("ft_write: %lu\n", ft_write(1, NULL, 1));
	printf("\n------ Test 4 ------\n");
	printf("fd --> -1\n");
	printf("write: %lu\n", write(-1, "Hello World!", 12));
	printf("ft_write: %lu\n", ft_write(-1, "Hello World!", 12));
	printf("\n------ Test 5 ------\n");
	printf("String --> 'Hello World! Len --> 3'\n");
	printf("write: %lu\n", write(1, "Hello World!", 3));
	printf("ft_write: %lu\n", ft_write(1, "Hello World!", 3));
}

void	test_strdup()
{
	printf("\n\n------ ft_strdup ------\n");
	char *test;
	char *ft_test;
	printf("\n------ Test 1 ------\n");
	printf("String --> 'Hello World!'\n");
	test = strdup("Hello World!");
	ft_test = ft_strdup("Hello World!");
	printf("strdup: %s\n", test);
	printf("ft_strdup: %s\n", ft_test);
	free (test);
	free (ft_test);
	printf("\n------ Test 2 ------\n");
	printf("String --> ''\n");
	test = strdup("");
	ft_test = ft_strdup("");
	printf("strdup: %s\n", test);
	printf("ft_strdup: %s\n", ft_test);
	free (test);
	free (ft_test);
}
