#include "tests.h"


void	test_strdup(void)
{
	char	str[33];
	char*	ret;
	int		ran;
	int		c;

	print_test_name("STRDUP");
	str[0] = '\0';
	for (int i = 0; i < 100; i++)
	{
		ran = rand() % 31;
		for (int j = 0; j < ran; j++)
		{
			c = rand() % 255;
			str[j] = c;
		}
		str[ran] = '\0';
		ret = ft_strdup(str);
		if (strcmp(str, ret))
		{
			print_fail();
			return;
		}
		free(ret);
	}
	print_pass();
}
