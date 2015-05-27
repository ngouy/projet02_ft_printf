/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_opt_len_aux1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:19:20 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 16:33:50 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					ft_found_opt_len(const char *str)
{
	int		ret;

	ret = 0;
	while (ft_strstr("# +-hljzsSpdDioOuUxXcC0123456789.",
				ft_strsub(str, 0, 1)))
	{
		ret++;
		if (ft_strstr("sSpdDioOuUxXcC", ft_strsub(str, 0, 1)))
			return (ret);
		str++;
	}
	return (-ret);
}

void				check_n_sort(t_opt *opt, char *str, char c)
{
	char	*s;

	s = ft_strchr(str, c);
	if (s)
		opt->flagu = ft_strjoin(opt->flagu, ft_strsub(s, 0, 1));
	return ;
}

int					ft_nbr(char *str)
{
	int		ret;
	int		i;

	str = ft_strsub(str, 0, ft_abs(ft_found_opt_len(str)));
	i = 0;
	ret = 0;
	while (*str && strchr("# +-hljz0123456789.", *str))
	{
		if (ft_isdigit(*str) && ((*(str - 1) && *(str - 1) != '.' &&
						!ft_isdigit(*(str - 1))) || !(*(str - 1))))
		{
			if (ft_atoi(str) != 0)
				ret = ft_atoi(str);
			while (str[i] == '0')
				i++;
			str += i + ft_strlen(ft_itoa(ret)) - 1;
		}
		str++;
	}
	return (ret);
}

char				*found_hlz(char *str)
{
	char	*t;
	char	*ret;
	char	*temp;

	str = ft_strsub(str, 0, ft_abs(ft_found_opt_len(str)));
	ret = "";
	if (ft_strstr(str, "ll"))
		ret = ft_strjoin(ret, "ll");
	else if (ft_strstr(str, "l"))
		ret = ft_strjoin(ret, "l");
	else if (ft_strstr(str, "z"))
		ret = ft_strjoin(ret, "z");
	else if (ft_strstr(str, "j"))
		ret = ft_strjoin(ret, "j");
	else if (ft_strstr(str, "hh"))
		ret = ft_strjoin(ret, "hh");
	else if (ft_strstr(str, "h"))
		ret = ft_strjoin(ret, "h");
	(!ret[0]) ? (ret = NULL) : ret;
	return (ret);
}

void				ft_spec_z(t_opt *opt)
{
	if (opt->out != 's' && opt->out != 'S')
		opt->mod[0] = 'l';
	else
		opt->mod[0] = 0;
	if (opt->out == 'd' || opt->out == 'D')
		opt->out = 'D';
}
