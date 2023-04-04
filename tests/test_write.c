#include "tests.h"


void	test_write(void)
{
	char	str[33];
	char	buffer[50];
	char	final1[50];
	char	final2[50];
	int		ran;
	int		c;
	int		pipes[2];
	pid_t	pid;

	ssize_t	ret;

	print_test_name("WRITE");

	ret = ft_write(255, "buffer\n", 7);
	if (ret != -1 || errno != EBADF)
	{
		print_fail();
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		final1[0] = '\0';
		final2[0] = '\0';
		ran = rand() % 31;
		for (int j = 0; j < ran; j++)
		{
			c = rand() % 255;
			str[j] = c;
		}
		str[ran] = '\0';
		if (pipe(pipes))
		{
			dprintf(2, "Error while creating pipes\n");
			return ;
		}
		pid = fork();
		if (pid == -1)
		{
			dprintf(2, "Error while forking\n");
			return ;
		}
		if (!pid)
		{
			close(pipes[0]);
			ret = write(pipes[1], str, strlen(str));
			ft_putssize_t_fd(ret, pipes[1]);
			close(pipes[1]);
			exit (0);
		}
		close(pipes[1]);
		while ((ret = read(pipes[0], buffer, 49)) > 0)
		{
			buffer[ret] = '\0';
			strcat(final1, buffer);
		}
		close(pipes[0]);

		if (pipe(pipes))
		{
			dprintf(2, "Error while creating pipes\n");
			return ;
		}
		pid = fork();
		if (pid == -1)
		{
			dprintf(2, "Error while forking\n");
			return ;
		}
		if (!pid)
		{
			close(pipes[0]);
			ret = ft_write(pipes[1], str, strlen(str));
			ft_putssize_t_fd(ret, pipes[1]);
			close(pipes[1]);
			exit (0);
		}
		close(pipes[1]);
		while ((ret = read(pipes[0], buffer, 49)) > 0)
		{
			buffer[ret] = '\0';
			strcat(final2, buffer);
		}
		close(pipes[0]);

		if (strcmp(final1, final2))
		{
			print_fail();
			return;
		}
	}
	print_pass();
}
