/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:07:08 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/13 09:42:18 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void			to_smtint(long int n, int *sign, char **ret, int i)
{
	if (n < 0)
	{
		(*ret)[*sign] = '-';
		n = -n;
		(*sign)++;
	}
	if (n >= (i % 100))
	{
		to_smtint(n / (i % 100), sign, ret, i);
		(*sign)++;
		if (n % (i % 100) > 9)
		{
			(*ret)[*sign] = (i > 100) ? (n % (i % 100) + 55) :
				(n % i + 55 + (97 - 65));
		}
		else
			(*ret)[*sign] = n % (i % 100) + 48;
	}
	else
		(*ret)[*sign] = n + 48;
}

static void			to_smtuns(long unsigned n, int *sign, char **ret, int i)
{
	if (n >= (unsigned)(i % 100))
	{
		to_smtuns(n / (i % 100), sign, ret, i);
		(*sign)++;
		if (n % (i % 100) > 9)
			(*ret)[*sign] = (i > 100) ? (n % (i % 100) + 55) :
				(n % i + 55 + (97 - 65));
		else
			(*ret)[*sign] = n % (i % 100) + 48;
	}
	else
	{
		if (n % (i % 100) > 9)
			(*ret)[*sign] = (i > 100) ? (n + 55) : (n + 55 + (97 - 65));
		else
			(*ret)[*sign] = n % (i % 100) + 48;
	}
}

static int			ft_aux1(int c)
{
	int		j;

	j = -1;
	(c == 'D') ? (j = 10) : j;
	(c == 'O') ? (j = 8) : j;
	(c == 'U') ? (j = 10) : j;
	(c == 'x') ? (j = 16) : j;
	(c == 'X') ? (j = 116) : j;
	return (j);
}

char				*long_int_to_smt(long int i, char c)
{
	int				sign;
	char			*str;
	int				j;

	if (i == LONG_MIN)
	{
		if (!(c == 'O' || c == 'U'))
			return ("-9223372036854775808");
		return ((c == 'O') ? (STR_LONG_MIN_OCT) : ("9223372036854775808"));
	}
	sign = 0;
	j = -1;
	str = malloc(sizeof(char) * 30);
	while (sign != 30)
		str[sign++] = '\0';
	sign = 0;
	j = ft_aux1(c);
	if (c == 'D')
		to_smtint(i, &sign, &str, j);
	else
		to_smtuns((unsigned long)i, &sign, &str, j);
	return (str);
}
