/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:23:26 by ifounas           #+#    #+#             */
/*   Updated: 2024/09/28 19:24:01 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void    ft_putstr(char *str)
{
        int     i;

        i = -1;
        while (str[++i] != '\0')
                write(1, &str[i], 1);
	write(1, "\n", 1);
}

int	ft_puttab(int j, char *str)
{       
        char    res[100];
        int     k;

        k = 0;
        while (str[j] != '\n')
        {
                res[k] = str[j];
                k++;
                j++;
        }
        ft_putstr(res);
	while (k > 0)
	{
		res[k] = '\0';
		k--;
	}
	return (j);
}

//This function separate a string
void	ft_strtok(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = i; 
		if (str[i] >= '0' && str[i] <= '9')
			ft_ultimate_atoi(str);
		/*
		if (str[j] == ':')
			i = ft_puttab(j + 2, str); */
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != ':')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + str[i] - 48;
		i++;
	}
	return (nb);
}

int	*ft_write_tab(char *str)
{
	int	i;
	int	j;
	int	nb;
	char	tab[3][10];

	i = 0;
	j = 0;
	nb = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 11)
		{
			nb = ft_atoi(str);
			if ()
			tab[i][j] = 
			j++;
		}
		i++;
	}
	return (tab);
}

int	main(void)
{
	char	c[1000];
	int		file_read;
	int		file_open;
	//char	*smalls[3][10];
	//char	*bigs[22];

	file_open = open("numbers.dict", O_RDONLY);
	if (file_open != -1)
	{
		file_read = read(file_open, c, sizeof(c));
		ft_strtok(c);
		//ft_putstr(c);
	}
	else
		ft_putstr("Error while trying to read the file");
	close(file_open);
}
