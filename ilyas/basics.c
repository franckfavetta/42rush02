/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:25:17 by ifounas           #+#    #+#             */
/*   Updated: 2024/09/29 14:50:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_fill_tab(char *smalls[3][10], int nb, char *str);

void    ft_putstr(char *str)
{
        int     i;

        i = -1;
        while (str[++i] != '\0')
                write(1, &str[i], 1);
        write(1, "\n", 1);
}

int     ft_atoi(char *str, int i, char *smalls[3][10], char *res)
{
        int     j;
        long long int   nb;

        j = 0;
        nb = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
                if (nb < 100)
                        nb = (nb * 10) + (str[i] - 48);
                j++;
                i++;
        }
        if (j < 4 && !(nb >= 11 && nb <= 19))
		ft_fill_tab(smalls, nb, res);
        return (i);
}

int     ft_puttab(int j, char *str, char *smalls[3][10])
{
        char    res[100];
        int     k;

        k = 0;
	while (str[j] != ':')
		j++;
	j = j + 2;
        while (str[j] != '\n')
        {
                res[k] = str[j];
                k++;
                j++;
        }
        ft_putstr(res);
	ft_atoi(str, j, smalls, res);
        while (k > 0)
        {
                res[k] = '\0';
                k--;
        }
        return (j);
}
