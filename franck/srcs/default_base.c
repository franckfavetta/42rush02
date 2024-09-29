/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffavetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:46:18 by ffavetta          #+#    #+#             */
/*   Updated: 2024/09/26 12:46:23 by ffavetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	fill_digits(t_data *pdt)
{
	pdt->smalls[0][0] = "";
	pdt->smalls[0][1] = "one";
	pdt->smalls[0][2] = "two";
	pdt->smalls[0][3] = "three";
	pdt->smalls[0][4] = "four";
	pdt->smalls[0][5] = "five";
	pdt->smalls[0][6] = "six";
	pdt->smalls[0][7] = "seven";
	pdt->smalls[0][8] = "eigth";
	pdt->smalls[0][9] = "nine";
}

void	fill_tens(t_data *pdt)
{
	pdt->smalls[1][0] = "";
	pdt->smalls[1][1] = "ten";
	pdt->smalls[1][2] = "twenty";
	pdt->smalls[1][3] = "thirty";
	pdt->smalls[1][4] = "fourty";
	pdt->smalls[1][5] = "fifty";
	pdt->smalls[1][6] = "sixty";
	pdt->smalls[1][7] = "seventy";
	pdt->smalls[1][8] = "eighty";
	pdt->smalls[1][9] = "ninety";
}

void	fill_hundreds(t_data *pdt)
{
	pdt->smalls[2][0] = "";
	pdt->smalls[2][1] = "one hundred";
	pdt->smalls[2][2] = "two hundred";
	pdt->smalls[2][3] = "three hundred";
	pdt->smalls[2][4] = "four hundred";
	pdt->smalls[2][5] = "five hundred";
	pdt->smalls[2][6] = "six hundred";
	pdt->smalls[2][7] = "seven hundred";
	pdt->smalls[2][8] = "heigth hundred";
	pdt->smalls[2][9] = "nine hundred";
}

void	fill_bigs(t_data *pdt)
{
	pdt->bigs[00] = "";
	pdt->bigs[01] = "thousand";
	pdt->bigs[02] = "million";
	pdt->bigs[03] = "billion";
	pdt->bigs[04] = "trillion";
	pdt->bigs[05] = "quadrillion";
	pdt->bigs[06] = "quintillion";
	pdt->bigs[07] = "sextillion";
	pdt->bigs[8] = "septillion";
	pdt->bigs[9] = "octillion";
	pdt->bigs[10] = "nonillion";
	pdt->bigs[11] = "decillion";
	pdt->bigs[12] = "undecillion";
	pdt->bigs[13] = "duodecillion";
	pdt->bigs[14] = "tredecillion";
	pdt->bigs[15] = "quattuordecillion";
	pdt->bigs[16] = "quindecillion";
	pdt->bigs[17] = "sexdecillion";
	pdt->bigs[18] = "septendecillion";
	pdt->bigs[19] = "octodecillion";
	pdt->bigs[20] = "novemdecillion";
	pdt->bigs[21] = "vigintillion";
	pdt->bigs[101] = "centillion";
}

void	fill_default_base(t_data *pdt)
{
	int	i;

	i = 0;
	while(i < 200)
		pdt->bigs[i++] = "";
	fill_digits(pdt);
	fill_tens(pdt);
	fill_hundreds(pdt);
	fill_bigs(pdt);
}
