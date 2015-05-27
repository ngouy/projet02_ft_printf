/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 11:14:24 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/13 10:14:25 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static wchar_t		*ft_war3(int i)
{
	wchar_t	*tab;
	int		j;

	tab = malloc(sizeof(int) * 5);
	j = i;
	i = (j >> 18);
	tab[0] = i + 240;
	i = (j >> 12) - ((j >> 18) << 6);
	tab[1] = i + 128;
	i = (j >> 6) - ((j >> 12) << 6);
	tab[2] = i + 128;
	i = (j) - ((j >> 6) << 6);
	tab[3] = i + 128;
	tab[4] = '\0';
	return (tab);
}

static wchar_t		*ft_war2(int i)
{
	wchar_t	*tab;
	int		j;

	tab = malloc(sizeof(int) * 4);
	j = i;
	i = (j >> 12);
	tab[0] = i + 224;
	i = (j >> 6) - ((j >> 12) << 6);
	tab[1] = i + 128;
	i = (j) - ((j >> 6) << 6);
	tab[2] = i + 128;
	tab[3] = 0;
	return (tab);
}

static wchar_t		*ft_war1(int i)
{
	wchar_t	*tab;
	int		j;

	tab = malloc(sizeof(int) * 3);
	j = i;
	i = (j >> 6);
	tab[0] = i + 192;
	i = (j) - ((j >> 6) << 6);
	tab[1] = i + 128;
	tab[2] = 0;
	return (tab);
}

static wchar_t		*ft_war0(int i)
{
	wchar_t	*tab;

	tab = malloc(sizeof(int) * 2);
	tab[0] = i;
	tab[1] = '\0';
	return (tab);
}

wchar_t				*ft_put_wart(int i, int j)
{
	wchar_t	*ret;

	(j == 3) ? (ret = ft_war3(i)) : ret;
	(j == 2) ? (ret = ft_war2(i)) : ret;
	(j == 1) ? (ret = ft_war1(i)) : ret;
	(j == 0) ? (ret = ft_war0(i)) : ret;
	return (ret);
}
