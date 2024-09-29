/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
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

void	ft_putsn(char *str, int *dosep)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	if (p > str)
	{
		if (*dosep)
			write(1, " ", 1);
		p = str;
		while (*p != '\0')
			write(1, p++, 1);
		*dosep = 1;
	}
}

int	error(int errcode, char *msg)
{
	char *p;

	p = msg;
	while (*p != '\0')
		p++;
	write(1, msg, p - msg);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_data	dt;
	char	sn[600];
	char	*p;

	if (argc < 2 || argc > 3)
		return (error(1, "Error\n"));
	p = argv[1 + (argc == 3)];
	while (*p == ' ' || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '-')
		return (error(2, "Error\n"));
	if (*p == '+')
		p++;
	while (*p == '0')
		p++;
	if (!(*p >= '1' && *p <= '9'))
		if (*p == '.')
			return (error(3, "Error\n"));
		else
			*p = '0';
	fill_default_base(&dt);
	fill_default_except(&dt);
	if (argc == 3)
		if (loadfile(&dt))
				return (error(4, "Dict Error\n"));
	extract_nb(sn, p);
	if (parse_nb(sn, &dt))
			return (error(4, "Dict Error\n"));
	write(1, "\n", 1);
	return (0);
}

//Created with Createx
/*

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

	printf("%d\n", atoi("   d -0000123fghj"));
	return (0);
}
*/
