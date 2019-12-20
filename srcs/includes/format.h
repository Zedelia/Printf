/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 11:43:47 by mbos        ###    #+. /#+    ###.fr     */
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
void	format_add_input(t_format *s_format, t_input *l_input);

#endif
