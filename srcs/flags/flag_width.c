/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_width.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		case_percent(t_flag *l_flag, char *width, va_list params)
{
	if (width[1] == '*')
	{
		if (!(l_flag->width = get_di(params)))
			return (False);
		if (*(int *)(l_flag->width) < 0)
		{
			*(int *)(l_flag->width) = -*(int *)(l_flag->width);
			if (l_flag->type != '-')
				l_flag->type = '-';
		}
		return (True);
	}
	if (!(l_flag->width = get_width_preci(width)))
		return (False);
	return (True);
}

t_bool		flag_width(t_flag *l_flag, char *width, va_list params)
{
	if (width[0] == '*')
	{
		if (!(l_flag->width = get_di(params)))
			return (False);
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
		return (False);
	return (True);
}
