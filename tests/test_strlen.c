#include "tests.h"


void	test_strlen(void)
{
	char	str[33];
	int		ran;
	size_t	ret_cst;
	size_t	ret_std;

	print_test_name("STRLEN");
	str[0] = '\0';
	ret_cst = ft_strlen(str);
	ret_std = strlen(str);
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
