/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:23:26 by ifounas           #+#    #+#             */
/*   Updated: 2024/09/29 14:51:07 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void    ft_putstr(char *str);
int	ft_puttab(int j, char *str, char *smalls[3][10]);
int     ft_atoi(char *str, int i, char *smalls[3][10], char *res);

void	ft_fill_tab(char *smalls[3][10], int nb, char *str)
{
	if (nb < 10)
		smalls[0][nb] = str;
	else if (nb < 100)
		smalls[1][nb/10] = str;
	else if (nb > 90 && nb < 1000)
		smalls[2][nb/100] = str;
}

void	ft_strtok(char *str, char *smalls[3][10])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	smalls[0][0] = "truc";
	while (str[i] != '\0')
	{
		j = i;
		/*if (str[j] >= '0' && str[j] <= '9')
			i = ft_atoi(str, i, smalls);
		*/i = ft_puttab(j, str, smalls);
		i++;
	}
}

int	main(void)
{
	char	c[1000];
	int		file_read;
	int		file_open;
	int		i;
	int		j;
	char	*smalls[3][10];
	
	i = 0;
	j = 0;
	file_open = open("numbers.dict", O_RDONLY);
	if (file_open != -1)
	{
		file_read = read(file_open, c, sizeof(c));
		ft_strtok(c, smalls);
		printf("%s", smalls[0][0]);
		/* while (i < 3)
		{
			j = 0;
			while (j < 10)
			{
				printf("%s", smalls[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}*/
		//ft_putstr(c);
	}
	else
		ft_putstr("Error while trying to read the file");
	close(file_open);
}
