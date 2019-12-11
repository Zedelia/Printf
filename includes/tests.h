/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:40:50 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:05:17 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "ft_printf.h"
/*
** Tests functions
*/
t_bool				false_ret(const char *namefunc);

void				show_format(t_format *s_format);
void				show_one_pattern(t_pattern *l_pattern);
void				show_pattern(t_pattern *l_pattern);
void				show_one_flag(t_flag *l_flag);
void				show_flag(t_flag *l_flag);
void				init_show_varg(void);

typedef void		(t_show_varg)(t_pattern*);
t_show_varg			*g_show_varg[size];

void				show_varg(t_pattern *l_pattern);
void				show_c(t_pattern *l_pattern);
void				show_s(t_pattern *l_pattern);
void				show_p(t_pattern *l_pattern);
void				show_di(t_pattern *l_pattern);
void				show_u(t_pattern *l_pattern);
void				show_x(t_pattern *l_pattern);
void				show_percent(t_pattern *l_pattern);

#endif
