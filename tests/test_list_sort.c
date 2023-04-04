#include "tests.h"

int	greater(void *data1, void *data2)
{
	return (*((int *)data1) - *((int *)data2));
}

int	less(void *data1, void *data2)
{
	return (-(*((int *)data1) - *((int *)data2)));
}

int	even_and_greater(void *data1, void *data2)
{
	int	first;
	int	second;

	first = *((int *) data1);
	second = *((int *) data2);

	if (!(first % 2) && second % 2)
		return (-1);
	else if (first % 2 && !(second % 2))
		return (1);
	return (first - second);
}

void	test_list_sort(void)
{
	int		ran;
	int		num;
	int		numbers[100];
	t_list	*head;
	t_list	*current;
	int		(*funcs[3])(void*, void*);

	print_test_name("LIST_SORT");
	head = NULL;
	current = NULL;
	funcs[0] = greater;
	funcs[1] = less;
	funcs[2] = even_and_greater;
	ft_list_sort(&head, funcs[0]);
	if (head)
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
			numbers[j] = rand() % INT_MAX;
			current->data = (void *)(numbers + j) ;
			head = current;
		}
		num = rand() % 3;
		ft_list_sort(&head, funcs[num]);
		current = head;
		while (current && current->next)
		{
			if (funcs[num](current->data, current->next->data) > 0)
			{
				print_fail();
				clear_list(head);
				return;
			}
			current = current->next;
		}
		clear_list(head);
	}
	print_pass();
}
