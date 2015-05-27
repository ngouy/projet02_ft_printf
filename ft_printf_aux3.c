/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:53:03 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:07:56 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_printf_an(char *test, wchar_t **temp1, wchar_t *temp2)
{
	int		j;
	int		i;
	int		l;

	l = 0;
	j = l;
	i = ft_strlen(test) + 5;
	while (j != i)
	{
		if (test[j++] == 'c')
		{
			while (*temp2++)
				(*temp1)[l++] = *(temp2 - 1);
		}
		else
			(*temp1)[l++] = test[j - 1];
	}
}

wchar_t				*ft_testccc(t_opt *opt, va_list ap, int *cpt)
{
	char		*test;
	wchar_t		*temp1;
	wchar_t		*temp2;

	temp2 = int_to_c(va_arg(ap, wchar_t));
	if (*temp2 == 0)
		opt->spec = 10;
	else
		opt->larg -= (ft_wcharlen(temp2) - 1);
	test = "c";
	opt->out = 'c';
	opt->prec = 0;
	test = ft_apply_opt(test, opt);
	opt->out = 'C';
	temp1 = malloc(sizeof(wchar_t) * ft_strlen(test) + 5);
	ft_printf_an(test, &temp1, temp2);
	return (temp1);
}
