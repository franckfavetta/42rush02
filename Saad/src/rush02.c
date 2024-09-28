/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saidriss <saidriss@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:14:33 by saidriss          #+#    #+#             */
/*   Updated: 2024/09/28 13:48:31 by saidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_getnb(int fd)
{
	int		i;
	char	c[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		return (NULL);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*ft_getval(int fd, char *c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		return (NULL);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

void	read_space(int fd, char *c)
{
	read(fd, c, 1);
	while (c[0] == ' ')
		read(fd, c, 1);
	if (c[0] == ':')
		read(fd, c, 1);
	while (c[0] == ' ')
		read(fd, c, 1);
}

t_list	*extract(char *file)
{
	int		i;
	int		fd;
	t_list	*tab;
	char	c[1];

	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(t_list) * 33);
	if (fd == -1 || (!tab))
		return (NULL);
	i = 0;
	while (i++ < 32)
	{
		tab[i].nb = ft_atoi(ft_getnb(fd));
		read_space(fd, c);
		tab[i].val = ft_getval(fd, c);
		tab[i].val = ft_strdup(tab[i].val);
	}
	close(fd);
	return (tab);
}
