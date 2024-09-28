/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:23:26 by ifounas           #+#    #+#             */
/*   Updated: 2024/09/28 14:12:02 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}

void	ft_putnbr(int nb)
{
	char	str[1000];
	int		i;

	i = 0;
	while (nb >= 1)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	main(void)
{
	char	c[1000];
	int		file_read;
	int		file_open;

	file_open = open("numbers.dict", O_RDONLY);
	if (file_open != -1)
	{
		ft_putstr("file correctly openned\n");
		file_read = read(file_open, c, sizeof(c));
		ft_putstr(c);
	}
	else
		ft_putstr("Error while trying to read the file");
	close(file_open);
}
