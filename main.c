#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);

int	main(int ac, char **av)
{
	char	*src = "Hello World";
	char	*a1="🙂";
	char	*a2="😉";
	char	dst[64];
	if (ac < 2)
	{
		printf("Enter the string for which you would like to know the length as a parameter\n");
		return (1);
	}
	printf("%ld\n", ft_strlen(av[1]));
	printf("Copied: [%s]\n", ft_strcpy(dst, src));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, ""), strcmp(src, ""));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(a1, a1), strcmp(a1, a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("", a1), strcmp("", a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("z", a1), strcmp("z", a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(a2, a1), strcmp(a2, a1));
//	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("Z", "a"), strcmp("Z", "a"));
//	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("a", "Za"), strcmp("a", "Za"));
//	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("", "Za"), strcmp("", "Za"));
//	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("Za", ""), strcmp("Za", ""));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("Za", src), strcmp("Za", src));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, "Za"), strcmp(src, "Za"));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, "Hallo World"), strcmp(src, "Hallo World"));
	return (0);
}
