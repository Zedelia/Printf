/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:28:04 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		input_parser(t_input *l_input, va_list params)
{
	t_flag *l_flag;

	if (!(input_cpy(l_input)))
		return (false_ret(__func__));
	l_input->len = ft_strlen(l_input->input_cpy) + 1;
	if (is_indicator(l_input->input_cpy[0]) == True)
	{
		if (!(get_arg(l_input, params)))
			return (false_ret(__func__));
	}
	if (is_indicator(l_input->input_cpy[0]) == False)
	{
		if (!(flag_init(&l_flag, l_input->input_cpy, params)))
			return (false_ret(__func__));
		l_input->l_flag = l_flag;
		if (!(get_arg(l_input, params)))
			return (false_ret(__func__));
	}
	return (True);
}
