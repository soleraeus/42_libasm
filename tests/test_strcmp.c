#include "tests.h"


void	test_strcmp(void)
{
	char	str1[33];
	char	str2[33];
	int		ran;
	int		c;
	size_t	ret_cst;
	size_t	ret_std;

	print_test_name("STRCMP");

	// Test two empty strings
	str1[0] = '\0';
	str2[0] = '\0';
	ret_cst = ft_strcmp(str1, str2);
	ret_std = strcmp(str1, str2);
	if (ret_std != ret_cst)
	{
		print_fail();
		return;
	}

	// Test one empty string
	ran = rand() % 31;
	for (int i = 0; i < ran; i++)
	{
		c = rand() % 256;
		str2[i] = c;
	}
	str2[ran] = '\0';
	ret_cst = ft_strcmp(str1, str2);
	ret_std = strcmp(str1, str2);
	if (ret_std != ret_cst)
	{
		print_fail();
		return;
	}

	// Almost the same
	str1[0] = 'h';
	str1[1] = 'e';
	str1[2] = 'l';
	str1[3] = 'l';
	str1[4] = 'o';
	str1[5] = ' ';
	str1[6] = 'Y';
	str1[7] = 'o';
	str1[8] = 'u';
	str1[9] = '\0';

	str2[0] = 'h';
	str2[1] = 'e';
	str2[2] = 'l';
	str2[3] = 'l';
	str2[4] = 'o';
	str2[5] = ' ';
	str2[6] = 'X';
	str2[7] = 'o';
	str2[8] = 'u';
	str2[9] = '\0';

	ret_cst = ft_strcmp(str1, str2);
	ret_std = strcmp(str1, str2);
	if (ret_std != ret_cst)
	{
		print_fail();
		return;
	}

	// Random strings
	for (int i = 0; i < 100; i++)
	{
		ran = rand() % 31;
		for (int j = 0; j < ran; j++)
		{
			c = rand() % 256;
			str1[j] = c;
		}
		str1[ran] = '\0';
		ran = rand() % 31;
		for (int j = 0; j < ran; j++)
		{
			c = rand() % 256;
			str2[j] = c;
		}
		str2[ran] = '\0';
		ret_cst = ft_strcmp(str1, str2);
		ret_std = strcmp(str1, str2);
		if (ret_std != ret_cst)
		{
			print_fail();
			return;
		}
	}
	print_pass();
}
