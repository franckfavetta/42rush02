/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saidriss <saidriss@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:23:51 by saidriss          #+#    #+#             */
/*   Updated: 2024/09/28 13:49:22 by saidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_list
{
	int		nb;
	char	*val;
}		t_list;
long long int		ft_atoi(char *str);
char				*ft_strdup(char *src);
void				ft_putstr(char *str);
char				*ft_getnb(int fd);
char				*ft_getval(int fd, char *c);
t_list				*extract(char *file);

#endif
