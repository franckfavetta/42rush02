/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_except.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffavetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:46:18 by ffavetta          #+#    #+#             */
/*   Updated: 2024/09/26 12:46:23 by ffavetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	fill_default_except(t_data *pdt)
{
	pdt->exkey[00] = 0;
	pdt->exkey[11] = 11;
	pdt->exkey[12] = 12;
	pdt->exkey[13] = 13;
	pdt->exkey[14] = 14;
	pdt->exkey[15] = 15;
	pdt->exkey[16] = 16;
	pdt->exkey[17] = 17;
	pdt->exkey[18] = 18;
	pdt->exkey[19] = 19;
	pdt->exval[00] = "zero";
	pdt->exval[11] = "eleven";
	pdt->exval[12] = "twelve";
	pdt->exval[13] = "thirteen";
	pdt->exval[14] = "fourteen";
	pdt->exval[15] = "fifteen";
	pdt->exval[16] = "sixteen";
	pdt->exval[17] = "seventeen";
	pdt->exval[18] = "eighteen";
	pdt->exval[19] = "nineteen";
}
