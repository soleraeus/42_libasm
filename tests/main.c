#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;


size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);
void ft_list_push_front(t_list **begin_list, void *data);
int	ft_list_size(t_list *lst);
void ft_list_sort(t_list **begin_list, int (*cmp)() );
void ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)(), void (*free_fct)(void*));

void	free_data(void* data)
{
	(void)data;
	return;
}

int	main(int ac, char **av)
{
	char	*src = "Hello World";
	char	*a1="🙂";
	char	*a2="😉";
	char	dst[64];
	ssize_t	ret;
	int		fd;
	char	*res;

	if (ac < 2)
	{
		printf("Enter the string for which you would like to know the length as a parameter\n");
		return (1);
	}
	printf("%ld\n", ft_strlen(av[1]));
	printf("Copied: [%s]\n", ft_strcpy(dst, src));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, ""), strcmp(src, ""));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(a1, a1), strcmp(a1, a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("", a1), strcmp("", a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("z", a1), strcmp("z", a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(a2, a1), strcmp(a2, a1));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp("Za", src), strcmp("Za", src));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, "Za"), strcmp(src, "Za"));
	printf("cst strcmp: %d\nstd strcmp: %d\n", ft_strcmp(src, "Hallo World"), strcmp(src, "Hallo World"));

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
	fd = open("main.c", O_RDONLY);
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


	return (0);
}
