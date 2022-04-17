/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:26:04 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/14 21:14:25 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
char *ft_strjoin(char *line,char c)
{
	int len = 0;
	char *str;
	int i = 0;
	while (line && line[len])
	{
		len++;
	}
	str = malloc(len + 2);
	if (line)
	{
		while (line[i])
		{
			str[i] = line[i];
			i++;
		}
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	free(line);
	return(str);
}

char *get_next_line(int fd)
{
	char *line = NULL;
	char c;
	int i;
	i = read(fd,&c,1);
	while (i)
	{
		line = ft_strjoin(line,c);
		if (c == '\n')
			break;
		i = read(fd,&c,1);
	}
	return (line);
}
int main ()
{
	int fd = open("file",0);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}