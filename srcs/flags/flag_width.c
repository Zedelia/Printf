/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:55 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		case_percent(t_flag *l_flag, char *width, va_list params)
{
	if (width[1] == '*')
	{
		if (!(l_flag->width = get_di(params)))
			return (false_ret(__func__));
		if (*(int *)(l_flag->width) < 0)
		{
			*(int *)(l_flag->width) = -*(int *)(l_flag->width);
			if (l_flag->type != '-')
				l_flag->type = '-';
		}
		return (True);
	}
	if (!(l_flag->width = get_width_preci(width)))
		return (false_ret(__func__));
	return (True);
}

t_bool		flag_width(t_flag *l_flag, char *width, va_list params)
{
	int i;

	i = 0;
	while (width[i] == '-' || width[i] == '0')
		i++;
	if (width[i] == '*')
	{
		if (!(l_flag->width = get_di(params)))
			return (false_ret(__func__));
		if (*(int *)(l_flag->width) < 0)
		{
			*(int *)(l_flag->width) = -*(int *)(l_flag->width);
			if (l_flag->type != '-')
				l_flag->type = '-';
		}
		return (True);
	}
	if ((l_flag->type == '-' && width[0] == '0')
			|| (l_flag->type == '0' && width[0] == '-'))
		return (case_percent(l_flag, width, params));
	if (!(l_flag->width = get_width_preci(width)))
		return (false_ret(__func__));
	return (True);
}
