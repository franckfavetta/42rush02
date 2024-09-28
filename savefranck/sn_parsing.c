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

#include "rush.h"

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

t_range	*exception(t_range *prg, t_data *pdt)
{
}

void	parse_nb(char *sn, t_data *pdt)
{
	char	*p;
	t_range	rg;

	p = sn;
	while (*p != '\0')
		p++;
	p -= 3;
	while (p >= sn)
	{
		rg.i_digit = pdt->smalls[2][*(p + 2) - '0';
		rg.i_ten = pdt->smalls[1][*(p + 1) - '0';
		rg.i_hundred = pdt->smalls[0][*(p + 0) - '0';
		rg.i_big = pdt->bigs[(p - sn) / 3];
		exception(&rg, pdt);
		
		ft_putsn(pdt->smalls[2][*(p + 2) - '0'], 1);
		ft_putsn(pdt->smalls[1][*(p + 1) - '0'], 1);
		ft_putsn(pdt->smalls[0][*(p + 0) - '0'], 1);
		ft_putsn(pdt->bigs[(p - sn) / 3], 1);
		p -= 3;
	}
}
