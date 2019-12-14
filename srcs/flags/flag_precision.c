/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_precision.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 20:51:18 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 14:38:30 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_precision(t_flag *l_flag, char *precision, va_list params)
{
	if (precision[0] == '*')
	{
		if (!(l_flag->precision = get_di(params)))
			return (false_ret(__func__));
		if (*(int *)(l_flag->precision) < 0 && l_flag->flag_type == '0')
		{
			*(int *)(l_flag->precision) = *(int *)(l_flag->width);
			l_flag->arg_neg = True;
		}
		return (True);
	}
	if (!is_indicator(precision[0]) && !(l_flag->precision = get_width_preci(precision)))
		return (false_ret(__func__));
	return (True);
}
