/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:21:59 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:22:01 by mbos             ###   ########lyon.fr   */
/*                                                                            */
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
