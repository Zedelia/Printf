/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:39:37 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:10:31 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "ft_printf.h"
/*
** Format functions
** init, free, use and modify t_format
*/
t_bool	format_init(t_format **s_format, const char *format, va_list params);
void	format_free(t_format **s_format);
t_bool	format_parser(t_format *s_format, char *format, va_list params);
void	format_add_pattern(t_format *s_format, t_pattern *l_pattern);
t_bool	format_replace_pattern(t_format *s_format);

#endif
