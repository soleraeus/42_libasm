#include "tests.h"

static int	greater(void *data1, void *data2)
{
	if (*((int *)data1) > *((int *)data2))
		return (0);
	return (1);
}

static int	less(void *data1, void *data2)
{
	if (*((int *)data1) < *((int *)data2))
		return (0);
	return (1);
}

static int	even_or_odd(void *data1, void *data2)
{
	int	first;
	int	second;

	first = *((int *) data1);
	second = *((int *) data2);

	if ((!(first % 2) && second % 2)
		|| (first % 2 && !(second % 2)))
		return (0);
	return (1);
}

static void	clear_list_alloced(t_list *head)
{
	t_list	*current;
	t_list	*prev;

	current = head;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev->data);
		free(prev);
	}
}

static void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		printf("%d\n", *((int *)current->data));
		current = current->next;
	}
	printf("\n\n");
}

void	test_list_remove_if(void)
{
	int		ran;
	int		num;
	int		*number;
	t_list	*head;
	t_list	*current;
	int		(*funcs[3])(void*, void*);

	print_test_name("LIST_REMOVE_IF");
	head = NULL;
	current = NULL;
	funcs[0] = greater;
	funcs[1] = less;
	funcs[2] = even_or_odd;
	ft_list_remove_if(&head, 0, funcs[0], free);
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
				clear_list_alloced(head);
				return ;
			}
			current->next = head;
			number = malloc(sizeof(int));
			if (!number)
			{
				dprintf(2, "Malloc error\n");
				free(current);
				clear_list_alloced(head);
				return ;
			}
			*number = rand() % INT_MAX;
			current->data = (void *)number ;
			head = current;
		}
		num = rand() % 3;
		ran = rand() % INT_MAX;
		ft_list_remove_if(&head, (void *)&ran, funcs[num], free);
		current = head;
		while (current)
		{
			if (funcs[num](current->data, (void *) &ran) == 0)
			{
				printf("Failed on:\nPicked function: %s\nPicked number: %d\n", num == 0 ? "Remove if greater" : (num == 1 ? "Remove if lower" : ( ran % 2 ? "Remove if not odd" : "Remove if not even")), ran);
				print_list(head);
				print_fail();
				clear_list_alloced(head);
				return;
			}
			current = current->next;
		}
		clear_list_alloced(head);
	}
	print_pass();
}
