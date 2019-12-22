/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:04 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 12:50:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		flag_parser(t_flag *l_flag, char *flags, va_list params)
{
	if (flags[0] == '0' || flags[0] == '-')
	{
		l_flag->type = flags[0];
		if (!(flag_width(l_flag, &flags[1], params)))
			return (False);
	}
	else
	{
		l_flag->type = 'N';
		if (!(flag_width(l_flag, &flags[0], params)))
			return (False);
	}
	if (ft_isincharset('.', flags))
	{
		if (!flag_preci(l_flag, ft_strchr(flags, '.') + 1, params))
			return (False);
	}
	return (True);
}
