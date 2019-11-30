/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:03:18 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:07:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_parser(t_flag *l_flag, char *flags, va_list params)
{
	if (flags[0] == '0' ||flags[0] == '-')
	{
		l_flag->flag_type = flags[0];
		if (!(flag_width(l_flag, flags, params)))
			return (false_ret(__func__));
	}
	if (ft_isdigit(flags[0]) == True)
	{
		l_flag->flag_type = 'N';
		if (!(flag_width(l_flag, flags, params)))
			return (false_ret(__func__));
	}
	return (True);
}
