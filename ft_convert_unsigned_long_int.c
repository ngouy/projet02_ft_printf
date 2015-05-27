/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned_long_int.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:07:08 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/13 09:46:54 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void			to_smtint(unsigned long int n, int *sign, char **ret, int i)
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
			(*ret)[*sign] = (i > 100) ? (n % (i % 100) + 55) :
				(n % i + 55 + (97 - 65));
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

char				*unsigned_long_int_to_smt(unsigned long int i, char c)
{
	int				sign;
	char			*str;
	int				j;

	sign = 0;
	j = -1;
	str = malloc(sizeof(char) * 30);
	while (sign != 30)
		str[sign++] = '\0';
	sign = 0;
	(c == 'D') ? (j = 10) : j;
	(c == 'O') ? (j = 8) : j;
	(c == 'U') ? (j = 10) : j;
	(c == 'x') ? (j = 16) : j;
	(c == 'X') ? (j = 116) : j;
	if (c == 'D')
		to_smtint(i, &sign, &str, j);
	else
		to_smtuns((unsigned long)i, &sign, &str, j);
	return (str);
}
