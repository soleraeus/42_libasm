#include <stdio.h>

size_t ft_strlen(const char *s);

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Enter the string for which you would like to know the length as a parameter\n");
		return (1);
	}
	printf("Size of string [%s]: %ld\n", av[1], ft_strlen(av[1]));
	return (0);
}
