/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:45:58 by omykolai          #+#    #+#             */
/*   Updated: 2017/12/26 17:21:33 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

char	*get_str(char *str)
{
	char *res;

	if (str == NULL)
		return "NULL";
	str = ft_strjoin("\"", str);
	res = ft_strjoin(str, "\"");
	free(str);
	return (res);
}

int 	check_memcmp(const void *s1, const void *s2, int res)
{
	int val;

	val = ft_memcmp(s1, s2, 5);
	if (val != res)
		printf(">> Your ft_memcmp(%s,%s, 5) == %d\n\n", 
			get_str((char*)s1),
			get_str((char*)s2), val);
	else
		return (0);
	return (1);
}
int 	check_strcmp(const char *s1, const char *s2, int res)
{
	int val;

	val = ft_strcmp(s1, s2);
	if (val != res)
		printf(">> Your ft_strcmp(%s,%s) == %d\n\n", 
			get_str((char*)s1),
			get_str((char*)s2), val);
	else
		return (0);
	return (1);
}
int 	check_strncmp(const char *s1, const char *s2, int res)
{
	int val;

	val = ft_strncmp(s1, s2, 5);
	if (val != res)
		printf(">> Your ft_strncmp(%s,%s, 5) == %d\n\n", 
			get_str((char*)s1),
			get_str((char*)s2), val);
	else
		return (0);
	return (1);
}

int 	check_strequ(const char *s1, const char *s2, int res)
{
	int val;

	val = ft_strequ(s1, s2);
	if (val != res)
		printf(">> Your ft_strnequ(%s,%s) == %d\n\n", 
			get_str((char*)s1),
			get_str((char*)s2), val);
	else
		return (0);
	return (1);
}

int 	check_strnequ(const char *s1, const char *s2, int res)
{
	int val;

	val = ft_strnequ(s1, s2, 5);
	if (val != res)
		printf(">> Your ft_strnequ(%s,%s, 5) == %d\n\n", 
			get_str((char*)s1),
			get_str((char*)s2), val);
	else
		return (0);
	return (1);
}

int 	check_strjoin(const char *s1, const char *s2, char *res)
{
	char *val;

	val = ft_strjoin(s1, s2);
	if (((!val || !res) && val != res) || 
		((val && res) && strcmp(val, res) != 0))
		printf(">> Your ft_strjoin(%s,%s) == %s\n\n", 
			get_str((char*)s1),
			get_str((char*)s2), get_str(val));
	else
		return (0);
	return (1);
}

int 	check_putstr_speed(void)
{
	int fd = open("temp1", O_CREAT);
	int len = 10000;
	char *str = ft_memalloc(len);

	clock_t before;
	clock_t difference1;
	clock_t difference2;

	ft_memset(str, '0', len - 1);

	before = clock();
	ft_putstr_fd(str, fd);
	difference1 = clock() - before;

  	before = clock();
  	write(fd, str, ft_strlen(str));
  	difference2 = clock() - before;
  	close(fd);
	
  	system("chmod 666 temp1");
  	system("rm temp1");
  	if ((difference2 == 0 && difference1 > 3) ||
  		difference1 / difference2 > 3)
  		printf(">> You probably write one symbol at a time in your ft_putstr_fd, which is slow. \nPS: Also check your ft_putstr, ft_putendl, ft_putendl_fd!\n\n");
  	else
  		return (0);
  	return (1);
}

int		main(int argc, char **argv)
{
	int res;

	res = 0;
	
	if (argc == 2)
	{
	switch (argv[1][0])
	{
			case '0':
			res += check_memcmp(NULL, NULL, 0);
			break;
			case '1':
			res += check_strcmp(NULL, NULL, 0);
			break;
			case '2':
			res += check_strncmp(NULL, NULL, 0);
			break;
			case '3':
			res += check_strequ(NULL, NULL, 1);
			break;
			case '4':
			res += check_strnequ(NULL, NULL, 1);
			break;
			case '5':
			res += check_putstr_speed();
			break;
			case '6':
			res += check_strjoin(NULL, "abc", "abc");
			res += check_strjoin("abc", NULL, "abc");
			res += check_strjoin(NULL, NULL, NULL);
		}
	}
	if (res != 0)
		system("touch res");

	return (0);
}