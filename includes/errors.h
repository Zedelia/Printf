/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:42:25 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:02:51 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
#include "ft_printf.h"
/*
** Error_functions pointers Tab
*/
typedef enum
{
	_several_flags = 0,
	_too_many_stars,
	_zero_sc,
	_precision_c,
	_digit_stars_before_flag,
	_digit_stars_together,
	errors_size
}	t_type_error;

void				init_error_fct_tab(void);
typedef t_bool		(t_get_error_fct)(t_pattern*);
t_get_error_fct		*g_get_error_fct[errors_size];

t_bool	get_errors(t_pattern *l_pattern);
t_bool	error_several_flags(t_pattern *l_pattern);
t_bool	error_too_many_stars(t_pattern *l_pattern);
t_bool	error_zero_sc(t_pattern *l_pattern);
t_bool	error_precision_c(t_pattern *l_pattern);
t_bool	error_digit_stars_before_flag(t_pattern *l_pattern);
t_bool	error_digit_stars_together(t_pattern *l_pattern);

#endif
