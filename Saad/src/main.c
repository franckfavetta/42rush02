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

int	main(int ac, char **av)
{
	t_list	*tab;
	int		*first;
	int		addr_first;

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
