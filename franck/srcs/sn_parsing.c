/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sn_parsing.c                                       :+:      :+:    :+:   */
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
	while (p > str - 1)
		*sn++ = *p--;
	i = 0;
	while (i++ < lzf)
		*sn++ = '0';
	*sn = '\0';
}

t_range	*exception(int nrg, t_range *prg, t_data *pdt, int *dosep)
{
	int	rg01;

	ft_putsn(pdt->smalls[2][prg->hn], dosep);
	rg01 = prg->tn * 10 + prg->dg;
	if (rg01 >= 11 && rg01 <= 19)
		ft_putsn(pdt->exval[rg01], dosep);
	else
	{
		ft_putsn(pdt->smalls[1][prg->tn], dosep);
		ft_putsn(pdt->smalls[0][prg->dg], dosep);
	}
	ft_putsn(pdt->bigs[prg->bg], dosep);
}

int	parse_nb(char *sn, t_data *pdt)
{
	char	*p;
	t_range	rg;
	int		dosep;

	p = sn;
	while (*p != '\0')
		p++;
	dosep = 0;
	if ((p - sn == 3) && sn[0] == '0' && sn[1] == '0' && sn[2] == '0')
		ft_putsn(pdt->exval[0], &dosep);
	else{
		p -= 3;
		while (p >= sn)
		{
			rg.hn = *(p + 2) - '0';
			rg.tn = *(p + 1) - '0';
			rg.dg = *(p + 0) - '0';
			rg.bg = (p - sn) / 3;
			exception(rg.hn * 100 + rg.tn * 10 + rg.dg, &rg, pdt, &dosep);
			p -= 3;
		}
	}
	return (0);
}
