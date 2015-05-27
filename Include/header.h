/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:28:17 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/17 17:04:27 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*
** Includes
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

/*
**	macro
*/

# define STR_LONG_MIN_OCT "1000000000000000000000"

/*
** structures
*/

typedef struct		s_opt
{
	int				spec;
	int				space;
	char			*flagu;
	int				larg;
	int				prec;
	char			*mod;
	char			out;
}					t_opt;

/*
** prototypes
*/

wchar_t				*ft_testccc(t_opt *opt, va_list ap, int *cpt);
void				ft_printf_an(char *test, wchar_t **temp1, wchar_t *temp2);
void				ft_app_an(char *str, t_opt *opt);
int					sst(wchar_t *str);
void				check_n_sort(t_opt *opt, char *str, char c);
void				ft_spec_z(t_opt *opt);
int					ft_nbr(char *str);
char				*found_hlz(char *str);
wchar_t				*ft_adjust_prec(wchar_t *str, t_opt *opt);
wchar_t				*ft_spec_prec(wchar_t *str, t_opt *opt);
wchar_t				*ft_str_to_spec_str(char *str);
char				*ft_xuido(t_opt *opt, va_list ap);
char				*ft_with_h(t_opt *opt, va_list ap);
int					disp_n_count(void *str, int flagu, t_opt *opt);
void				switch_space(const char **str);
char				*ft_add_c(char *str, char c, int range);
int					ft_abs(int i);
void				add_smt_bef(char **str, t_opt *opt);
void				del_0(char **ret, int i);
char				*ft_del_c(char *str, int range);
int					ft_abs(int i);
char				*ft_apply_opt(char *str, t_opt *opt);
int					ft_wcharlen(wchar_t *st);
int					ft_wchartlen(wchar_t *st);
int					ft_printf(const char *format, ...);
char				*int_to_smt(int i, char c);
char				*long_int_to_smt(long int i, char c);
char				*unsigned_long_int_to_smt(unsigned long int i, char c);
char				*ft_ptr(long int i, t_opt *opt);
int					ft_found_args(const char *format, int *type, char **opt);
wchar_t				*ft_put_wart(int i, int j);
wchar_t				*int_to_c(int i);
int					ft_found_opt_len(const char *str);
t_opt				*short_args(char *str);

#endif
