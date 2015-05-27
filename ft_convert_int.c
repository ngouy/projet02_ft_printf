/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:07:08 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/13 09:32:21 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void			to_smtint(int n, int *sign, char **ret, int i)
{
	if (n < 0)
	{
		(*ret)[*sign] = '-';
		n = -n;
		(*sign)++;
	}
	if (n >= i)
	{
		to_smtint(n / i, sign, ret, i);
		(*sign)++;
		if (n % i > 9)
			((*ret)[*sign] = n % i + 55 + (97 - 65));
		else
			(*ret)[*sign] = n % i + 48;
	}
	else
		(*ret)[*sign] = n + 48;
}

static void			to_smtuns(unsigned n, int *sign, char **ret, int i)
{
	if (n >= ((unsigned)i % 100))
	{
		to_smtuns(n / (i % 100), sign, ret, i);
		(*sign)++;
		if (n % (i % 100) > 9)
		{
			(i > 100) ? ((*ret)[*sign] = n % (i % 100) + 55) :
				((*ret)[*sign] = n % (i % 100) + 55 + (97 - 65));
		}
		else
			(*ret)[*sign] = n % (i % 100) + 48;
	}
	else
	{
		if (n % (i % 100) > 9)
		{
			(i > 100) ? ((*ret)[*sign] = n % (i % 100) + 55) :
				((*ret)[*sign] = n % (i % 100) + 55 + (97 - 65));
		}
		else
			(*ret)[*sign] = n % (i % 100) + 48;
	}
}

wchar_t				*int_to_c(int i)
{
	int		j;
	wchar_t	*ret;

	if (i == 0)
	{
		return (L"\0");
	}
	j = 0;
	(i > 65535) ? (j = 3) : j;
	(i > 2047 && i <= 65535) ? (j = 2) : j;
	(i > 127 && i <= 2047) ? (j = 1) : j;
	ret = ft_put_wart(i, j);
	return (ret);
}

static int			ft_aux1(int c)
{
	int		j;

	j = -1;
	(c == 'd' || c == 'i') ? (j = 10) : j;
	(c == 'o') ? (j = 8) : j;
	(c == 'b') ? (j = 2) : j;
	(c == 'u') ? (j = 10) : j;
	(c == 'X') ? (j = 116) : j;
	(c == 'x') ? (j = 16) : j;
	return (j);
}

char				*int_to_smt(int i, char c)
{
	int				sign;
	char			*str;
	int				j;

	if (i == -2147483648)
	{
		if (!(c == 'o' || c == 'u'))
			return (str = "-2147483648");
		return ((c == 'o') ? ("20000000000") : ("2147483648"));
	}
	sign = 0;
	j = -1;
	str = malloc(sizeof(char) * 30);
	while (sign != 20)
		str[sign++] = '\0';
	sign = 0;
	j = ft_aux1(c);
	if (c == 'd' || c == 'i')
		to_smtint(i, &sign, &str, j);
	else
		to_smtuns((unsigned)i, &sign, &str, j);
	return (str);
}
