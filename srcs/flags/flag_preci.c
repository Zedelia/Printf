/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_preci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:48 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_preci(t_flag *l_flag, char *preci, va_list params)
{
	if (preci[0] == '*')
	{
		if (!(l_flag->preci = get_di(params)))
			return (false_ret(__func__));
		if (*(int *)(l_flag->preci) < 0 && l_flag->type == '0')
		{
			*(int *)(l_flag->preci) = *(int *)(l_flag->width);
			l_flag->arg_weird = True;
		}
		return (True);
	}
	else if (preci[0] == 'p')
	{
		l_flag->arg_weird = True;
		l_flag->preci = 0;
	}
	if (!(l_flag->preci = get_width_preci(preci)))
		return (false_ret(__func__));
	return (True);
}
