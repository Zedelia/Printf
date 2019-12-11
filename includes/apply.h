/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:46:28 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:22:26 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef APPLY_H
# define APPLY_H
# include "ft_printf.h"
/*
** Convert functions
*/
t_bool	apply_di(t_pattern *l_pattern);
t_bool	apply_di_arg_zero(t_pattern *l_pattern);
t_bool	apply_di_zero_pos(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_di_zero_neg(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_di_tiret(char *copy_width, t_pattern *l_pattern);
t_bool	apply_cs(t_pattern *l_pattern);
t_bool	apply_cs_tiret(t_pattern *l_pattern, char *copy_result);
t_bool	apply_cs_none(t_pattern *l_pattern, char *copy_result);
t_bool	apply_di_zero(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_percent(t_pattern *l_pattern);

#endif
