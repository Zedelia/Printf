/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:02 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 11:58:05 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef APPLY_H
# define APPLY_H
# include "ft_printf.h"
/*
** Convert functions
*/
t_bool	apply_diux(t_pattern *l_pattern);
t_bool	apply_diux_arg_zero(t_pattern *l_pattern);
t_bool	apply_diux_zero_pos(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_diux_zero_neg(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_diux_tiret(char *cpy_width, t_pattern *l_pattern);
t_bool	apply_cs(t_pattern *l_pattern);
t_bool	apply_cs_tiret(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_cs_none(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_diux_zero(t_pattern *l_pattern, char *cpy_result);
t_bool	apply_percent(t_pattern *l_pattern);

#endif
