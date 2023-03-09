#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);

int	main(int ac, char **av)
{
	char	*src = "Hello World";
	char	dst[64];
	if (ac < 2)
	{
		printf("Enter the string for which you would like to know the length as a parameter\n");
		return (1);
	}
	printf("%ld\n", ft_strlen(av[1]));
	printf("Copied: [%s]\n", ft_strcpy(dst, src));
	return (0);
}
