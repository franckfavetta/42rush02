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

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_putsn(char *str, char *sep)
{
	char *p;

	p = str;
	while (*p != '\0')
		write(1, p++, 1);
	//if (sep != NULL)
	if(p > str)
		write(1, sep, 1);
}

int	error(int errcode)
{
	write(1, "Error\n", 6);
	return (errcode);
}

void	extract_nb(char *sn, char *str)
{
	char	*p;
	char	i;
	int		lzf;

	p = str;
	while (*p != '\0' && (*p >= '0' && *p <= '9'))
		p++;
	lzf = (3 - (p - str) % 3) * ((p - str) % 3 != 0);
	p--;
	while (*p != '\0' && (*p >= '0' && *p <= '9'))
		*sn++ = *p--;
	i = 0;
	while (i++ < lzf)
		*sn++ = '0';
	*sn = '\0';
}

void	parse_nb(char *sn, char *(*smalls)[10], char **bigs)
{
	char	*p;

	p = sn;
	while (*p != '\0')
		p++;
	p -= 3;
	while (p >= sn)
	{
		ft_putsn(smalls[2][*(p + 2) - '0'], " ");
		ft_putsn(smalls[1][*(p + 1) - '0'], " ");
		ft_putsn(smalls[0][*(p + 0) - '0'], " ");
		ft_putsn(bigs[(p - sn) / 3], " ");
		p -= 3;
	}
}


int main(int argc, char **argv)
{
	char	*smalls[3][10] = {
		{"zero", "one", "two", "three", "four", "five", "six", "seven", "heigth", "nine"},
		{"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "heighty", "ninety"},
		{"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", 
			"six hundred", "seven hundred", "heigth hundred", "nine hundred"}};
	char	*bigs[22] = {"", "thousand", "million", "billion", 
		"trillion", "quadrillion ", "quintillion", 
		"sextillion", "septillion", "octillion", 
		"nonillion", "decillion", "undecillion", 
		"duodecillion", "tredecillion", "quattuordecillion", 
		"quindecillion", "sexdecillion", "septendecillion", 
		"octodecillion", "novemdecillion", "vigintillion"};
	char	sn[600];
	char	*p;

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
	extract_nb(sn, p);
	ft_putstr(sn);
	parse_nb(sn, smalls, bigs);
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


