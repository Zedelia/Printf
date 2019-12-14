/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_width.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:21:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 13:12:25 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_width(t_flag *l_flag, char *width, va_list params)
{
	if (width[0] == '*')
	{
		if (!(l_flag->width = get_di(params)))
			return (false_ret(__func__));
		if (*(int *)(l_flag->width) < 0)
		{
			*(int *)(l_flag->width) = -*(int *)(l_flag->width);
			if (l_flag->flag_type != '-')
				l_flag->flag_type = '-';
		}
		return (True);
	}
	if (!(l_flag->width = get_width_preci(width)))
		return (false_ret(__func__));
	return (True);
}
