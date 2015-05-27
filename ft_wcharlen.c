/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 09:22:01 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/13 12:15:51 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_wcharlen(wchar_t *st)
{
	int		ret;

	ret = 0;
	while (st[ret])
		ret++;
	return (ret);
}

int			ft_wchartlen(wchar_t *st)
{
	int		ret;
	int		cpt;

	ret = 0;
	cpt = 0;
	while (st[cpt])
	{
		if (st[cpt] <= 127)
			ret++;
		else if (st[cpt] <= 2047)
			ret += 2;
		else if (st[cpt] < 65535)
			ret += 3;
		else
			ret += 4;
		cpt++;
	}
	return (ret);
}

int			sst(wchar_t *sstr)
{
	int		ret;

	if (!sstr)
		return (0);
	ret = 0;
	while (*sstr)
	{
		if (*sstr != '0' || *sstr != ' ')
			ret = 1;
	}
	return (ret);
}
