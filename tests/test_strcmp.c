#include <libasm.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tests.h"


void	test_strcmp(void)
{
	char	str1[33];
	char	str2[33];
	int		ran;
	size_t	ret_cst;
	size_t	ret_std;

	print_test_name("STRCMP");
	str1[0] = '\0';
	str2[0] = '\0';
	ret_cst = ft_strcmp(str1, str2);
	ret_std = strcmp(str1, str2);
	if (ret_std != ret_cst)
	{
		print_fail();
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		ran = rand() % 31;
		for (int j = 0; j < ran; j++)
		{
			str[j] = 'A';
		}
		str[ran] = '\0';
		ret_cst = ft_strlen(str);
		ret_std = strlen(str);
		if (ret_std != ret_cst)
		{
			print_fail();
			return;
		}
	}
	print_pass();
}
