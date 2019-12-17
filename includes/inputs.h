/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inputs.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 09:46:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef inputS_H
# define inputS_H

# include "ft_printf.h"
/*
** input functions
** init, free, use and modify t_format
*/
t_bool	input_init(t_input **l_input, char *format, va_list params);
void	input_free(t_input **l_input);
void	input_free_one(t_input **l_input);
t_bool	input_apply(char *format, t_input *conv);
t_bool	input_parser(t_input *l_input, va_list params);
void	input_add_flag(t_input *l_input, t_flag *l_flag);
t_bool	input_cpy(t_input *l_input);
t_bool	input_check(t_input *l_input);
t_bool	input_convert(t_input *l_input);
t_bool 	input_convert_init(t_input *l_input);

#endif
