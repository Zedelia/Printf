/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   patterns.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 11:59:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "ft_printf.h"
/*
** Pattern functions
** init, free, use and modify t_format
*/
t_bool	pattern_init(t_pattern **l_pattern, char *format, va_list params);
void	pattern_free(t_pattern **l_pattern);
void	pattern_free_one(t_pattern **l_pattern);
t_bool	pattern_apply(char *format, t_pattern *conv);
t_bool	pattern_parser(t_pattern *l_pattern, va_list params);
void	pattern_add_flag(t_pattern *l_pattern, t_flag *l_flag);
t_bool	pattern_cpy(t_pattern *l_pattern);
t_bool	pattern_check(t_pattern *l_pattern);
t_bool	pattern_convert(t_pattern *l_pattern);

#endif
