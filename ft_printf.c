/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:24:19 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:07:30 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <locale.h>

static void			ft_aux3(t_opt *opt, va_list ap, int *cpt, wchar_t *str)
{
	if ((opt->flagu && !ft_strchr(opt->flagu, '-')) || !opt->flagu)
	{
		while (opt->larg > 0)
		{
			(opt->flagu && ft_strchr((opt->flagu), '0')) ?
				(write (1, "0", 1)) : (write (1, " ", 1));
			*cpt = *cpt + 1;
			opt->larg--;
		}
	}
	while (*str)
		*cpt = *cpt + disp_n_count(int_to_c(*(str++)), 1, opt);
	if (opt->flagu && ft_strchr(opt->flagu, '-'))
	{
		while (opt->larg > 0)
		{
			(opt->flagu && ft_strchr((opt->flagu), '0')) ?
				(write (1, "0", 1)) : (write (1, " ", 1));
			*cpt = *cpt + 1;
			opt->larg--;
		}
	}
}

static void			ft_aux2(const char **str, t_opt *opt, va_list ap, int *cpt)
{
	wchar_t	*sstr;

	if (opt->out == 'S' || opt->out == 's')
	{
		if (opt->out == 'S')
			sstr = (va_arg(ap, wchar_t *));
		else
			sstr = ft_str_to_spec_str(va_arg(ap, char *));
		if (!sstr && (*cpt = *cpt + disp_n_count(NULL, 1, opt)))
		{
			(*str) = (*str) + ft_found_opt_len(*str);
			return ;
		}
		sstr = ft_adjust_prec(sstr, opt);
		(opt->larg) ? (opt->larg = opt->larg - ft_wchartlen(sstr)) : 0;
		ft_aux3(opt, ap, cpt, sstr);
	}
	(ft_found_opt_len(*str) >= 0) ? ((*str) = (*str) + ft_found_opt_len(*str))
		: ((*str) = (*str) - ft_found_opt_len(*str) + 1);
}

void				put_next_arg(const char **str, t_opt *opt, va_list ap,
		int *cpt)
{
	char		cc[2];

	cc[1] = '\0';
	if (opt->out == 'C')
		*cpt = *cpt + disp_n_count(ft_testccc(opt, ap, cpt), 1, opt);
	else if (ft_strchr("xXudio", opt->out))
		*cpt = *cpt + disp_n_count(ft_xuido(opt, ap), 0, opt);
	else if (opt->out == 'p')
		*cpt = *cpt + disp_n_count(ft_apply_opt(ft_ptr(va_arg(ap, long int),
						opt), opt), 0, opt);
	else if (ft_strchr("DOU", opt->out))
		*cpt = *cpt + disp_n_count(ft_apply_opt(long_int_to_smt(va_arg(ap,
							long int), opt->out), opt), 0, opt);
	else if (opt->out == 'c' || opt->out == 'R')
	{
		cc[0] = (opt->out == 'c') ? (va_arg(ap, int)) :
			(*(*str - ft_found_opt_len(*str)));
		opt->spec = (cc[0] == 0) ? (1) : (0);
		(opt->prec != 0 && opt->larg == 0) ? (opt->spec = 2) : opt->spec;
		(opt->prec != 0 && cc[0] != 0 && opt->larg == 0) ? (opt->spec = 4) :
			opt->spec;
		opt->out == 'c';
		*cpt = *cpt + disp_n_count(ft_apply_opt((char *)(cc), opt), 0, opt);
	}
	ft_aux2(str, opt, ap, cpt);
}

static const char	*ft_aux1(const char *format,
		int *cpt, t_opt **opt, va_list ap)
{
	format++;
	switch_space(&format);
	if (*format == '%')
	{
		(*cpt)++;
		write(1, format++, 1);
	}
	else if (*format)
	{
		if (ft_found_opt_len(format) == 0)
			switch_space(&format);
		else
		{
			*opt = short_args((char *)format);
			put_next_arg(&format, *opt, ap, cpt);
		}
	}
	return (format);
}

int					ft_printf(const char *format, ...)
{
	char	*l;
	t_opt	*opt;
	va_list	ap;
	int		cpt;

	l = setlocale(LC_ALL, "en_US.UTF-8");
	cpt = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (*format)
	{
		if ((*format == '%' && *(format + 1) == '%') || (*format != '%'))
		{
			(*format == '%') ? (format++) : format;
			write(1, format++, 1);
			cpt++;
		}
		else
			format = ft_aux1(format, &cpt, &opt, ap);
	}
	return (cpt);
}
