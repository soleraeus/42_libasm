#include "tests.h"


void	test_list_size(void)
{
	int		ran;
	int		ret;
	t_list	*head;
	t_list	*current;
	t_list	*prev;

	print_test_name("LIST_SIZE");
	head = NULL;
	prev = NULL;
	current = NULL;
	ret = ft_list_size(head);
	if (ret != 0)
	{
		print_fail();
		return;
	}
	for (int i = 0; i < 100; i++)
	{
		head = NULL;
		ran = rand() % 100;
		for (int j = 0; j < ran; j++)
		{
			current = malloc(sizeof(t_list));
			if (!current)
			{
				dprintf(2, "Malloc error\n");
				clear_list(head);
				return ;
			}
			current->next = head;
			head = current;
		}
		ret = ft_list_size(head);
		if (ret != ran)
		{
			print_fail();
			return;
		}
		clear_list(head);
	}
	print_pass();
}
