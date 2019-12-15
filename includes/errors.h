/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:15 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 11:58:31 by mbos        ###    #+. /#+    ###.fr     */
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
	_preci_cp,
	_digit_stars_before_flag,
	_digit_stars_together,
	_zeroflag_cp,
	errors_size
}	t_type_error;

void				init_error_fct_tab(void);
typedef t_bool		(t_get_error_fct)(t_pattern*);
t_get_error_fct		*g_get_error_fct[errors_size];

t_bool	get_errors(t_pattern *l_pattern);
t_bool	error_several_flags(t_pattern *l_pattern);
t_bool	error_too_many_stars(t_pattern *l_pattern);
t_bool	error_zero_sc(t_pattern *l_pattern);
t_bool	error_preci_cp(t_pattern *l_pattern);
t_bool	error_digit_stars_before_flag(t_pattern *l_pattern);
t_bool	error_digit_stars_together(t_pattern *l_pattern);
t_bool	error_zeroflag_cp(t_pattern *l_pattern);

#endif
