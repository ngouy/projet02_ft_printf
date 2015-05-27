/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:56:23 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:23:56 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		switch_space(const char **str)
{
	while (**str == ' ')
	{
		(*str)++;
	}
}

static int	ft_aux1(t_opt *opt)
{
	char	*str1;
	int		ret;

	ret = 0;
	if (opt->prec == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	(opt->prec == -1) ? (opt->prec = 0) : opt->prec;
	str1 = "(null)";
	while (ret != opt->larg)
	{
		if (ret < (opt->larg - opt->prec))
			write(1, "0", 1);
		else
			write(1, str1++, 1);
		ret++;
	}
	return (opt->larg);
}

static int	ft_aux2(void *str, int ret, t_opt *opt)
{
	char	*str1;
	int		ind;

	ind = 0;
	str1 = (char *)str;
	if ((opt->spec == 1 || opt->spec == 2) &&
			(opt->flagu && (ft_strchr(opt->flagu, '-'))))
	{
		write(1, "\0", 1);
		ind = 1;
	}
	while (str1[ret])
	{
		write(1, str1 + ret, 1);
		ret++;
	}
	if ((opt->spec == 1 || opt->spec == 2) && ind == 0)
		write(1, "\0", 1);
	if (opt->spec == 1 || opt->spec == 2)
		ret++;
	return (ret);
}

int			disp_n_count(void *str, int flagu, t_opt *opt)
{
	int		ret;
	int		tem;
	wchar_t	*sstr;

	tem = 0;
	ret = 0;
	if (opt->spec == 1)
		str++;
	if (!str)
		return (ft_aux1(opt));
	if (flagu == 0)
		ret = ft_aux2(str, ret, opt);
	else
	{
		sstr = (wchar_t *)str;
		if (opt->spec == 10 && (opt->flagu && ft_strchr(opt->flagu, '-')))
			write(1, "\0", 1);
		while (sstr[ret])
			write(1, sstr + (ret++), 1);
		if (opt->spec == 10 && (!opt->flagu || !ft_strchr(opt->flagu, '-')))
			write(1, "\0", 1);
		if (opt->spec == 10)
			ret++;
	}
	return (ret);
}

char		*ft_with_h(t_opt *opt, va_list ap)
{
	int					i;
	char				*ret;

	if (opt->out == 'd')
	{
		(opt->mod[1] && opt->mod[1] == 'h') ?
			(i = (signed char)va_arg(ap, int))
			: (i = (short int)va_arg(ap, int));
		ret = int_to_smt(i, opt->out);
	}
	else
	{
		(opt->mod[1] && opt->mod[1] == 'h') ?
			(i = (unsigned char)va_arg(ap, int))
			: (i = (unsigned short int)va_arg(ap, int));
		ret = int_to_smt(i, opt->out);
	}
	return (ret);
}
