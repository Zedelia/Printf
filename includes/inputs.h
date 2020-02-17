/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:17 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:22:20 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include "ft_printf.h"

/*
** input functions
** init, free, use and modify t_format
*/
t_bool		input_init(t_input **l_input, char *format, va_list params);
void		input_free(t_input **l_input);
void		input_free_one(t_input **l_input);
t_bool		input_apply(char *format, t_input *conv);
t_bool		input_parser(t_input *l_input, va_list params);
void		input_add_flag(t_input *l_input, t_flag *l_flag);
t_bool		input_cpy(t_input *l_input);
t_bool		input_indicator(t_input *l_input);
t_bool		input_convert(t_input *l_input);
t_bool		input_convert_init(t_input *l_input);

#endif
