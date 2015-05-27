/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 13:01:51 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 15:57:50 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_ptr(long int ptr, t_opt *opt)
{
	if (ptr == 0 && (opt->prec < 0 || opt->spec == 15))
	{
		return ("0x");
	}
	if (opt->prec > 0)
		opt->prec += 2;
	return (ft_strjoin("0x", long_int_to_smt(ptr, 'x')));
}
