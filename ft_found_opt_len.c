/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_opt_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:19:20 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:31:19 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void			ft_aux2(t_opt *opt)
{
	(opt->out == 'i') ? (opt->out = 'd') : opt->out;
	(opt->mod[0] == 'j' && opt->out != 's' && opt->out != 'S') ?
		(opt->mod[0] = 'l') : opt->mod[0];
	if (opt->mod[0] && opt->mod[0] == 'l')
	{
		if (opt->out == 'd' || opt->out == 'i')
			opt->out = 'D';
	}
	if (opt->mod[0] == 'z')
		ft_spec_z(opt);
	((opt->out == 'd' || opt->out == 'D') && opt->flagu &&
	strchr(opt->flagu, '#')) ? (*strchr(opt->flagu, '#') = 'n') : 'L';
	opt->out = ((opt->out) == 'c' && opt->mod[0] == 'l' && !opt->mod[1]) ?
		'C' : opt->out;
	opt->out = ((opt->out) == 's' && opt->mod[0] == 'l' && !opt->mod[1]) ?
		'S' : opt->out;
	((opt->mod[0] == 'j')) ? (opt->mod[0] = 0) : 'L';
	((opt->flagu[0]) == 0) ? (opt->flagu = NULL) : opt->flagu;
	((opt->mod[0]) == 0) ? (opt->mod = NULL) : opt->mod;
}

void				ft_init_opt(t_opt *opt, int flagu)
{
	if (flagu == 0)
	{
		opt->spec = 0;
		opt->space = 0;
		opt->flagu = "\0";
		opt->larg = 0;
		opt->prec = 0;
		opt->mod = "\0";
		opt->out = 0;
	}
	else
		ft_aux2(opt);
}

void				check_0(t_opt *opt, char *str)
{
	str = ft_strsub(str, 0, ft_abs(ft_found_opt_len(str)));
	if (ft_strchr(str, '.') && opt->out != 'c' && opt->out != 's'
			&& opt->out != 'S' && opt->out != 'C' && opt->out != 'R')
		return ;
	while (*str)
	{
		if (*str == '0' && ((*(str - 1) &&
						!ft_isdigit(*(str - 1))) || !*(str - 1)))
		{
			opt->flagu = ft_strjoin("0", opt->flagu);
			return ;
		}
		str++;
	}
}

static void			ft_aux1(char *str, t_opt *opt, char *to_check)
{
	str = ft_strsub(str, 0, ft_abs(ft_found_opt_len(str)));
	if (ft_strrchr(str, '.'))
	{
		if (ft_strrchr(str, '.') && ft_atoi(ft_strrchr(str, '.') + 1) == 0 &&
				((opt->flagu && !ft_strchr(opt->flagu, '#')) || !(opt->flagu)))
			opt->prec = -1;
		else
			opt->prec = ft_atoi(ft_strrchr(str, '.') + 1);
		if (opt->prec && (opt->out == 'o' || opt->out == 'O') && opt->flagu &&
				ft_strchr(opt->flagu, '#'))
			opt->prec--;
		if (ft_strrchr(str, '.') && ft_atoi(ft_strrchr(str, '.') + 1)
				== 0 && ((opt->flagu && ft_strchr(opt->flagu, '#'))))
			opt->spec = 15;
	}
	(opt->out == 'c' || opt->out == 'C') ? (opt->prec = 0) : opt->prec;
}

t_opt				*short_args(char *str)
{
	t_opt	*opt;
	char	*to_check;

	opt = malloc (sizeof(*opt));
	ft_init_opt(opt, 0);
	(ft_strchr(ft_strsub(str, 0, ft_abs(ft_found_opt_len(str))), ' ')) ?
		(opt->space = 1) : (opt->space);
	opt->out = (ft_found_opt_len(str) > 0) ?
		(*(str + ft_found_opt_len(str) - 1)) : ('R');
	(opt->out == 'i') ? (opt->out = 'd') : opt->out;
	to_check = "+-#";
	while (*to_check)
		check_n_sort(opt, str, *(to_check++));
	if (ft_nbr(str))
		opt->larg = (ft_nbr(str));
	if (found_hlz(str))
		opt->mod = ft_strjoin(opt->mod, found_hlz(str));
	check_0(opt, str);
	ft_init_opt(opt, 1);
	if (*(str - 1) == ' ')
		opt->space = 1;
	ft_aux1(str, opt, to_check);
	return (opt);
}
