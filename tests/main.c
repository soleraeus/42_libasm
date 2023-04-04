#include "tests.h"


void	free_data(void* data)
{
	(void)data;
	return;
}

int	main(int ac, char **av)
{

	(void)av;
	srand(time(NULL));
	char	*src = "Hello World";
	char	*a1="🙂";
	char	dst[64];
	ssize_t	ret;
	int		fd;
	char	*res;

	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	test_atoi_base();
	test_list_push_front();
	if (ac < 2)
	{
		printf("Enter the string for which you would like to know the length as a parameter\n");
		return (1);
	}
	ret = ft_write(1, src, ft_strlen(src));
	ft_write(1, "\n", 1);
	printf("Written: %ld\n", ret);
	ret = ft_write(2, a1, ft_strlen(a1));
	ft_write(2, "\n", 1);
	printf("Written: %ld\n", ret);
	ret = write(2, a1, ft_strlen(a1));
	write(2, "\n", 1);
	printf("Written: %ld\n", ret);
	ret = ft_write(5, "Nope\n", 5);
	if (ret < 0)
	{
		printf("Error on write with ret: %ld\n", ret);
		printf("errno value is: %d\n", errno);
		perror("ft_write");
	}
	else
		printf("That's not normal, got %ld\n", ret);
	fd = open("tests/main.c", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
	}
	else
	{
		ft_write(1, "\n\n", 2);
		while ((ret = ft_read(fd, dst, 63)) > 0)
		{
			dst[ret] = '\0';
			ft_write(1, dst, ret);
		}
	}

	printf("Dupping\n");
	res = ft_strdup(src);
	if (res)
	{
		ft_write(1, res, ft_strlen(res));
	}
	free(res);
	res = ft_strdup(a1);
	if (res)
	{
		ft_write(1, res, ft_strlen(res));
	}
	free(res);
	ft_write(1, "\n\n", 2);

	char	data[] = "Hello world";
	char	data2[] = "Number 2 is front";
	t_list	*ft = NULL;

	{
		t_list	*iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
		ft_list_sort(&ft, ft_strcmp);
		iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}
		

	printf("List size before adding elements: %d\n", ft_list_size(ft)); 
	
	ft_list_push_front(&ft, (void*)data);

	{
		t_list	*iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
		ft_list_sort(&ft, ft_strcmp);
		iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}


	ft_list_push_front(&ft, (void*)data2);
	if (ft == NULL)
		printf("Well that did not work");
	else
	{
		printf("It worked motherfuckas\n");
		t_list	*iter = ft;
		while (iter)
		{
			printf("%s\n", (char *)iter->data);
			iter = iter->next;
		}
	}
	printf("List size: %d\n", ft_list_size(ft)); 

	char	data3[] = "ZZZZZZ";
	char	data4[] = "~o";
	char	data5[] = "+";
	char	data6[] = "00";
	ft_list_push_front(&ft, (void*)data3);
	ft_list_push_front(&ft, (void*)data4);
	ft_list_push_front(&ft, (void*)data5);
	ft_list_push_front(&ft, (void*)data6);
	printf("diff: %d\n", strcmp(data6, data5));
	{
		printf("pre-sort\n");
		t_list	*iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
		ft_list_sort(&ft, strcmp);
		printf("post-sort\n");
		iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}

	

	ft_list_remove_if(&ft, (void *)"Hello world", strcmp, free_data);
	{
		printf("remove if Hello world\n");
		t_list	*iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}
	ft_list_remove_if(&ft, (void *)"+", strcmp, free_data);
	{
		printf("remove if first element\n");
		t_list	*iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}

	ft_list_remove_if(&ft, (void *)"~o", strcmp, free_data);
	{
		printf("remove if last element\n");
		t_list	*iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}



	t_list	*iter = ft;
	t_list	*tmp = NULL;
	while (iter)
	{
		tmp = iter->next;
		free(iter);
		iter = tmp;
	}
	ft = NULL;
	ft_list_remove_if(&ft, (void *)"~o", strcmp, free_data);
	{
		printf("remove if empty list\n");
		iter = ft;
		while (iter)
		{
			printf("Element: %s\n", (char *)iter->data);
			iter = iter->next;
		}
	}
	
	int new_nb = ft_atoi_base("		\n+---20ab8 9", "0123456789abcdef");
	printf("Number: %d\n", new_nb);

	return (0);
}
