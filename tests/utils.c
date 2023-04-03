#include <stdio.h>

void	print_test_name(char *name)
{
	printf("#################### %s ####################\n", name);
}

void	print_pass(void)
{
	printf("#################### ✅ ####################\n");
}

void	print_fail(void)
{
	printf("#################### ❌ ####################\n");
}
