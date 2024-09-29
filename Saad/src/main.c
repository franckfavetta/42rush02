/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saidriss <saidriss@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:15:45 by saidriss          #+#    #+#             */
/*   Updated: 2024/09/29 12:25:34 by saidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	getdec(int nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

double	getmult(double nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (getdec(nb));
}

void	ft_print(long long n, t_list *tab, int *first)
{
	int			i;
	long long	mult;

	i = 0;
	mult = getmult(n);
	if (mult >= 100)
		ft_print(n / mult, tab, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (tab[i].nb != mult)
		i++;
	ft_putstr(tab[i].val);
	if (mult != 0 && n % mult != 0)
		ft_print(n % mult, tab, first);
}

int	ft_case(int nb)
{
	if (nb == 1)
	{
		write(2, "Error", 5);
		return (0);
	}
	else if (nb == 2)
	{
		write(1, "zero", 4);
		return (0);
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_list	*tab;
	int		*first;
	int		addr;

	addr = 1;
	first = &addr;
	if (ac == 2)
	{
		if (ft_atoi(av[1]) < 0)
			ft_case(1);
		else if (ft_atoi(av[1]) == 0)
			ft_case(2);
		else
		{
			tab = extract("numbers.dict");
			ft_print(ft_atoi(av[1]), tab, first);
		}
	}
	else if (ac == 3)
	{
		tab = extract(av[1]);
		ft_print(ft_atoi(av[2]), tab, first);
	}
	write(1, "\n", 1);
	return (0);
}
