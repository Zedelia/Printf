/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_preci.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:11 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:43:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_preci(t_flag *l_flag, char *preci, va_list params)
{
	if (preci[0] == '*')
	{
		if (!(l_flag->preci = get_di(params)))
			return (false_ret(__func__));;
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
		return (false_ret(__func__));;
	return (True);
}
