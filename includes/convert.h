/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:44:50 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:17:40 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "ft_printf.h"

void				init_convert_fct_tab(void);
typedef t_bool		(t_convert_fct)(t_pattern*);
t_convert_fct		*g_convert_fct[size];

t_bool	pattern_convert(t_pattern *l_pattern);
t_bool	convert_di(t_pattern *l_pattern);
t_bool	convert_s(t_pattern *l_pattern);
t_bool	convert_c(t_pattern *l_pattern);
t_bool	convert_p(t_pattern *l_pattern);
t_bool	convert_u(t_pattern *l_pattern);
t_bool	convert_x(t_pattern *l_pattern);
t_bool	convert_percent(t_pattern *l_pattern);

#endif
