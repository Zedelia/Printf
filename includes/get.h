/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:43:41 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:05:04 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H
# include "ft_printf.h"

void				init_get_fct_tab(void);
typedef void		*(t_get_fct)(va_list);
t_get_fct			*g_get_fct[size];

t_bool				get_arg(t_pattern *l_pattern, va_list params);
void				*get_c(va_list params);
void				*get_s(va_list params);
void				*get_p(va_list params);
void				*get_di(va_list params);
void				*get_x(va_list params);
void				*get_percent(va_list params);

int					*get_width_preci(char *width_or_preci);
t_bool				get_indicator(t_pattern *l_pattern);

#endif
