/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_parser.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:03:33 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:03:34 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	pattern_add_flag(t_pattern *l_pattern, t_flag *l_flag)
{
		l_pattern->l_flag = l_flag;
}

t_bool 	pattern_parser(t_pattern *l_pattern, va_list params)
{
	t_flag *l_flag;

	if (!(pattern_cpy(l_pattern)))
		return (false_ret(__func__));
	l_pattern->len = ft_strlen(l_pattern->pattern_cpy) + 1;
	if (is_indicator(l_pattern->pattern_cpy[0]) == True)
	{
		if (!(get_arg(l_pattern, params)))
			return (false_ret(__func__));
	}
	if (is_indicator(l_pattern->pattern_cpy[0]) == False)
	{
		if (!(flag_init(&l_flag, l_pattern->pattern_cpy, params)))
			return (false_ret(__func__));
		pattern_add_flag(l_pattern, l_flag);
		if (!(get_arg(l_pattern, params)))
			return (false_ret(__func__));
	}
	return(True);
}
