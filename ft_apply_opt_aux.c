/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_opt_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 09:29:42 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:26:34 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_add_c(char *str, char c, int range)
{
	char	*ret;
	char	*cp;
	int		cpt;

	cpt = 0;
	ret = ft_strjoin(" ", str);
	while (cpt != range)
	{
		ret[cpt] = str[cpt];
		cpt++;
	}
	ret[cpt++] = c;
	while (str[cpt - 1])
	{
		ret[cpt] = str[cpt - 1];
		cpt++;
	}
	ret[cpt] = 0;
	return (ret);
}

void	add_smt_bef(char **str, t_opt *opt)
{
	int		ind;

	ind = 0;
	if (opt->out == 'd' || opt->out == 'D')
	{
		if (ft_strchr(opt->flagu, '+') && !ft_strchr(*str, '-'))
			*str = ft_add_c(*str, '+', 0);
		else if (opt->space && !ft_strchr(*str, '-'))
		{
			*str = ft_add_c(*str, ' ', 0);
		}
	}
	if (ft_strchr(opt->flagu, '#') && (ft_strcmp(*str, "0")))
	{
		(ft_strchr("xX", opt->out)) ? (*str = ft_add_c(*str, opt->out, 0)) :
			*str;
		(ft_strchr("oOxX", opt->out)) ? (*str = ft_add_c(*str, '0', 0)) : *str;
	}
}

void	del_0(char **rett, int i)
{
	int		cpt;
	char	*ret;

	ret = *rett;
	cpt = 0;
	while (ft_strlen(ret) > i)
	{
		while (ret[cpt] && ret[cpt] != '0')
		{
			cpt++;
			if (cpt > ft_strlen(ret))
				return ;
			if (ret[cpt + 1] && (ret[cpt + 1] == 'x' || (ret[cpt + 1] == 'X')))
				cpt = cpt + 2;
		}
		if (ret[cpt] == '0' && ret[cpt - 1] && (ret[cpt - 1] != '0'))
		{
			if (ft_strlen(ret) >= i)
				*rett = ft_del_c(ret, cpt);
		}
		ret = *rett;
	}
}

int		ft_abs(int i)
{
	return ((i >= 0) ? (i) : -i);
}

void	ft_app_an(char *str, t_opt *opt)
{
	if (!ft_strcmp(str, "0") && (opt->out == 'D' || opt->out == 'u' ||
				opt->out == 'x' || opt->out == 'X'))
	{
		if (opt->flagu && ft_strchr(opt->flagu, '+') &&
				(opt->out == 'x' || opt->out == 'X'))
			*(ft_strchr(opt->flagu, '+')) = 'L';
		opt->prec = (opt->spec == 15) ? -1 : opt->prec;
		opt->out = 'd';
	}
}
