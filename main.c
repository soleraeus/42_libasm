#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

int	main(int ac, char **av)
{
	char	*src = "Hello World";
	char	*a1="🙂";
	char	*a2="😉";
	char	dst[64];
	ssize_t	ret;
	int		fd;

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
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("Za", src), strcmp("Za", src));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, "Za"), strcmp(src, "Za"));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, "Hallo World"), strcmp(src, "Hallo World"));

	ret = ft_write(1, src, ft_strlen(src));
	ft_write(1, "\n", 1);
	printf("Written: %ld\n", ret);
	ret = ft_write(2, a1, ft_strlen(a1));
	ft_write(2, "\n", 1);
	printf("Written: %ld\n", ret);
	ret = write(2, a1, ft_strlen(a1));
	write(2, "\n", 1);
	printf("Written: %ld\n", ret);
	ret = ft_write(5, "Nope\n", 5);
	if (ret < 0)
	{
		printf("Error on write with ret: %ld\n", ret);
		printf("errno value is: %d\n", errno);
		perror("ft_write");
	}
	else
		printf("That's not normal, got %ld\n", ret);
	fd = open("main.c", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
	}
	else
	{
		ft_write(1, "\n\n", 2);
		while ((ret = ft_read(fd, dst, 63)) > 0)
		{
			dst[ret] = '\0';
			ft_write(1, dst, ret);
		}
	}
	return (0);
}
