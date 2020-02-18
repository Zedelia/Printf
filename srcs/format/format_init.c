/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:27:08 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	format_init(t_format **s_format, const char *format, va_list params)
{
	if (!(*s_format = malloc(sizeof(t_format))))
		return (false_ret(__func__));
	if (!((*s_format)->format = ft_strdup(format)))
		return (false_ret(__func__));
	(*s_format)->l_input = NULL;
	if (!(format_parser(*s_format, (*s_format)->format, params)))
		return (false_ret(__func__));
	(*s_format)->pointer_f = (*s_format)->format;
	return (True);
}
