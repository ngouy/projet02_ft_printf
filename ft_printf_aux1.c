/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:24:19 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 14:17:14 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_xuido(t_opt *opt, va_list ap)
{
	int					i;
	char				*ret;
	long int			li;
	unsigned long int	uli;

	if (opt->mod == NULL)
	{
		i = va_arg(ap, int);
		ret = int_to_smt(i, opt->out);
	}
	else if (opt->mod[0] == 'h')
		ret = ft_with_h(opt, ap);
	else if (opt->mod[0] == 'l')
	{
		if (opt->out == 'd')
		{
			li = va_arg(ap, long int);
			return (ret = long_int_to_smt(li, opt->out));
		}
		uli = va_arg(ap, long unsigned int);
		(opt->out == 'o' || opt->out == 'u') ? (opt->out = opt->out - 32) :
			opt->out;
		ret = unsigned_long_int_to_smt(uli, (opt->out));
	}
	return (ft_apply_opt(ret, opt));
}

wchar_t		*ft_str_to_spec_str(char *str)
{
	int		i;
	int		cpt;
	wchar_t	*ret;

	if (str == 0)
		return (0);
	cpt = 0;
	i = ft_strlen(str);
	ret = malloc(sizeof(wchar_t) * i + 1);
	while (str[cpt])
	{
		ret[cpt] = str[cpt];
		cpt++;
	}
	ret[cpt] = '\0';
	return (ret);
}

static int	ft_aux1(wchar_t *str, int cpt, int ind, int i)
{
	if (str[cpt] <= 127 && (ind + 1) <= i)
		ind++;
	else if (str[cpt] <= 2047 && (ind + 2) <= i)
		ind = ind + 2;
	else if (str[cpt] < 65535 && (ind + 3) <= i)
		ind += 3;
	else if ((ind + 4) <= i)
		ind += 4;
	else
		return (-1);
	return (ind);
}

wchar_t		*ft_spec_prec(wchar_t *str, t_opt *opt)
{
	int		i;
	int		ind;
	int		limit;
	int		cpt;
	wchar_t	*ret;

	i = 0;
	while (str[i])
		i++;
	cpt = 0;
	limit = 0;
	ind = 0;
	ret = malloc(sizeof(wchar_t) * i + 1);
	i = opt->prec;
	while (str[cpt] && limit == 0)
	{
		if (ft_aux1(str, cpt, ind, i) >= 0)
			ind = ft_aux1(str, cpt, ind, i);
		else
			limit = 1;
		ret[cpt] = str[cpt];
		cpt++;
	}
	ret[cpt - 1] = 0;
	return (ret);
}

wchar_t		*ft_adjust_prec(wchar_t *str, t_opt *opt)
{
	int		i;
	int		z;
	wchar_t	*cpy;
	wchar_t	*tmp;

	i = 0;
	if (opt->prec < 0)
	{
		return (L"");
	}
	if (opt->prec > ft_wchartlen(str))
		return (str);
	if (opt->prec == 0)
		return (str);
	return (ft_spec_prec(str, opt));
}
