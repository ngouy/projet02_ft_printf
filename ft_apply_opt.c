/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 09:29:42 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:25:21 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_del_c(char *str, int range)
{
	char	*ret;
	int		cpt;

	ret = ft_strdup(str);
	cpt = 0;
	while (cpt != range)
		cpt++;
	while (ret[cpt])
	{
		ret[cpt] = ret[cpt + 1];
		cpt++;
	}
	return (ret);
}

void	ft_rep_null(t_opt *opt)
{
	(opt->flagu) ? (opt->flagu) : (opt->flagu = "");
	(opt->mod) ? (opt->mod) : (opt->mod = "");
}

char	*ft_aux1(char *str, t_opt *opt)
{
	char	*ret;

	ret = "";
	if (!str)
		return (str);
	if (opt->prec == -1 && !ft_strcmp("0", str))
	{
		if (!ft_strcmp("0", str) && !ft_strchr("di", opt->out))
			return ("");
		else
		{
			while (opt->larg != 0)
			{
				ret = ft_strjoin(ret, " ");
				opt->larg--;
			}
			return (ret);
		}
	}
	if (ft_strchr("C", opt->out))
		return (str);
}

char	*ft_aux2(int sign, t_opt *opt, char *ret, int ind)
{
	while (opt->prec > 0)
	{
		if (opt->spec / 2 == 0 && opt->out != 'p')
			ret = ft_add_c(ret, '0', -sign);
		else if (opt->spec / 2 == 0 && opt->out)
			ret = ft_add_c(ret, '0', 2);
		opt->prec--;
	}
	add_smt_bef(&ret, opt);
	if (ft_strchr(opt->flagu, '0') && ind)
		del_0(&ret, opt->larg);
	else
	{
		opt->larg = opt->larg - ft_strlen(ret);
		while (opt->larg > 0)
		{
			(opt->flagu && ft_strchr(opt->flagu, '-')) ? (ret = ft_add_c(ret,
						' ', ft_strlen(ret))) : (ret = ft_add_c(ret, ' ', 0));
			opt->larg--;
		}
	}
	return (ret);
}

char	*ft_apply_opt(char *str, t_opt *opt)
{
	char	*ret;
	int		sign;
	int		ind;

	ft_app_an(str, opt);
	ind = 1;
	if ((!str || (!ft_strcmp("0", str) && opt->out != 'c' && opt->prec == -1)
				|| opt->out == 0))
		return (ft_aux1(str, opt));
	else
		ret = ft_strdup(str);
	ft_rep_null(opt);
	if (opt->prec && opt->prec > 0 && ft_strchr(str, '-'))
		opt->prec++;
	(ft_strchr(opt->flagu, '0') && !ft_strchr(opt->flagu, '-')) ?
		(opt->prec = opt->larg) : (opt->prec);
	sign = (ft_strchr(str, '-')) ? -1 : 0;
	if (opt->prec < ft_strlen(str))
		ind = 0;
	opt->prec = opt->prec - ft_strlen(str);
	(ft_strcmp(ret, "0x0")) ? (sign) : (sign = -2);
	ret = ft_aux2(sign, opt, ret, ind);
	return (ret);
}
