#include "tests.h"


void	test_list_push_front(void)
{
	int		tab[100];
	int		ran;
	t_list	*head;
	t_list	*current;
	t_list	*prev;

	print_test_name("LIST_PUSH_FRONT");
	head = NULL;
	prev = NULL;
	current = NULL;
	for (int i = 0; i < 100; i++)
	{
		ran = rand() % INT_MAX;
		tab[i] = ran;
		ft_list_push_front(&head, (void *)(tab + i));
	}
	current = head;
	for (int i = 99; i >= 0; i--)
	{
		if (!current || *((int *)(current->data)) != tab[i])
		{	
			print_fail();
			return;
		}
		prev = current;
		current = current->next;
		free(prev);
	}
	if (current)
	{
		print_fail();
		return;
	}
	print_pass();
}
