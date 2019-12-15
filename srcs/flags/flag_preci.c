/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_preci.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:11 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:02:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
			l_flag->arg_neg = True;
		}
		return (True);
	}
	if (!is_indicator(preci[0]) && !(l_flag->preci = get_width_preci(preci)))
		return (false_ret(__func__));
	return (True);
}
