#ifndef TESTS_H
# define TESTS_H
# define PRINT_WIDTH 67
# include "libasm.h"
# include <string.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

void	print_test_name(char *name);
void	print_pass(void);
void	print_fail(void);
void	ft_putssize_t_fd(ssize_t n, int fd);
void	test_strlen(void);
void	test_strcpy(void);
void	test_strcmp(void);
void	test_write(void);
void	test_read(void);
void	test_strdup(void);
void	test_atoi_base(void);
void	test_list_push_front(void);

#endif
