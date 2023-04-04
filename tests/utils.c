#include "tests.h"

void	print_test_name(char *name)
{
	size_t	len;
	size_t	print;

	len = strlen(name);
	print = PRINT_WIDTH - len;
	for (size_t i = 0; i < (print / 2); i++)
	{
		printf("#");
	}
	if (print % 2)
		printf("  %s  ", name);
	else
		printf(" %s  ", name);
	for (size_t i = 0; i < (print / 2); i++)
	{
		printf("#");
	}
	printf("\n");
}

void	print_pass(void)
{
	for (size_t i = 0; i < ((PRINT_WIDTH - 3) / 2); i++)
	{
		printf("#");
	}
	printf("  ✅  ");
	for (size_t i = 0; i < ((PRINT_WIDTH - 3) / 2); i++)
	{
		printf("#");
	}
	printf("\n\n\n");
}

void	print_fail(void)
{
	for (size_t i = 0; i < ((PRINT_WIDTH - 3) / 2); i++)
	{
		printf("#");
	}
	printf("  ❌  ");
	for (size_t i = 0; i < ((PRINT_WIDTH - 3) / 2); i++)
	{
		printf("#");
	}
	printf("\n\n\n");
}

void	ft_putssize_t_fd(ssize_t n, int fd)
{
	size_t	unb;

	if (fd >= 0)
	{
		if (n < 0)
		{
			unb = -n;
			write(fd, "-", 1);
		}
		else
			unb = n;
		if (unb >= 10)
		{
			ft_putssize_t_fd((unb / 10), fd);
			ft_putssize_t_fd((unb % 10), fd);
		}
		else
		{
			unb = unb + '0';
			write(fd, &unb, 1);
		}
	}
}

