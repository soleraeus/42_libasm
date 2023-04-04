#include "tests.h"


void	test_strcpy(void)
{
	char	str1[33];
	char	str2[33];
	int		ran;
	int		c;
	int		cmp;

	print_test_name("STRCPY");
	str1[0] = '\0';
	str2[0] = '\0';
	ft_strcpy(str2, str1);
	cmp = strcmp(str1, str2);
	if (cmp)
	{
		print_fail();
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		ran = rand() % 31;
		for (int j = 0; j < ran; j++)
		{
			c = rand() % 256;
			str1[j] = c;
		}
		str1[ran] = '\0';
		ft_strcpy(str2, str1);
		cmp = strcmp(str1, str2);
		if (cmp)
		{
			print_fail();
			return;
		}
	}
	print_pass();
}
