/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffavetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:46:18 by ffavetta          #+#    #+#             */
/*   Updated: 2024/09/26 12:46:23 by ffavetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>

typedef struct s_data
{
	char	*smalls[3][10];
	char	*bigs[22];
	int		exkey[1000];
	char	*exval[1000];
}	t_data;

typedef struct s_range
{
	int	i_digit;
	int	i_ten;
	int	i_hundred;
	int	i_big;
}	t_range;

void	parse_nb(char *sn, t_data *pdt);
void	extract_nb(char *sn, char *str);
void	ft_putstr(char *str);
void	ft_putsn(char *str, int sep);
int		error(int errcode);
void	fill_default(t_data *dt);

#endif
