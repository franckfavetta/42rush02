/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffavetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:46:18 by ffavetta          #+#    #+#             */
/*   Updated: 2024/09/26 12:46:23 by ffavetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_putsn(char *str, int sep)
{
	char	*p;

	if (sep && p > str)
		write(1, " ", 1);
	p = str;
	while (*p != '\0')
		write(1, p++, 1);
}

int	error(int errcode)
{
	write(1, "Error\n", 6);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_data	dt;
	char		sn[600];
	char		*p;

	if (argc < 2 || argc > 3)
		return (error(1));
	p = argv[1 + (argc == 3)];
	while (*p == ' ' || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '-')
		return (error(2));
	if (*p == '+')
		p++;
	if (!(*p >= '0' && *p <= '9'))
		return (error(3));
	//ft_putstr(p);
	fill_default(&dt);
	extract_nb(sn, p);
	//ft_putstr(sn);
	parse_nb(sn, &dt);
	return (0);
}

//Created with Createx
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

	printf("%d\n", atoi("  +  +123fghj"));
	return (0);
}
*/

