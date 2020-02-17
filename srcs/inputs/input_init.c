/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:27:57 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_init(t_input **l_input, char *format, va_list params)
{
	if (!(*l_input = malloc(sizeof(t_input))))
		return (false_ret(__func__));
	(*l_input)->next = NULL;
	(*l_input)->len = 0;
	(*l_input)->output = NULL;
	(*l_input)->varg = NULL;
	(*l_input)->p_input = format;
	(*l_input)->l_flag = NULL;
	(*l_input)->input_cpy = NULL;
	if (!(input_parser(*l_input, params)))
		return (false_ret(__func__));
	if (!(input_convert((*l_input))))
		return (false_ret(__func__));
	return (True);
}
