/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saidriss <saidriss@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:15:45 by saidriss          #+#    #+#             */
/*   Updated: 2024/09/28 22:05:13 by saidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_print(int n, t_list *tab, int *first)
{
	int	i;
	int	mult;

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

int	main(int ac, char **av)
{
	t_list	*tab;
	int		*first;
	int		addr_first;

	addr_first = 1;
	first = &addr_first;
	if (ac == 2)
	{
		if (ft_atoi(av[1]) == 0)
		{
			write(1, "zero\n", 5);
			return (0);
		}
		else if (ft_atoi(av[1]) < 0 || !ft_atoi(av[1]))
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
		tab = extract("numbers.dict");
		ft_print(ft_atoi(av[1]), tab, first);
		write(1, "\n", 1);
	}
	return (0);
}
