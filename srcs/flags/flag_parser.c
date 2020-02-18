/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:43 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_parser(t_flag *l_flag, char *flags, va_list params)
{
	if (flags[0] == '0' || flags[0] == '-')
	{
		l_flag->type = flags[0];
		if (!(flag_width(l_flag, &flags[1], params)))
			return (false_ret(__func__));
	}
	else
	{
		l_flag->type = 'N';
		if (!(flag_width(l_flag, &flags[0], params)))
			return (false_ret(__func__));
	}
	if (ft_isincharset('.', flags))
	{
		if (!flag_preci(l_flag, ft_strchr(flags, '.') + 1, params))
			return (false_ret(__func__));
	}
	return (True);
}
