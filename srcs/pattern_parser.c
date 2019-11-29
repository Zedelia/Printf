/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_parser.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 10:05:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 18:26:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	pattern_add_flag(t_pattern *l_pattern, t_flag *l_flag)
{
		l_pattern->l_flag = l_flag;
}


t_bool 	pattern_parser(t_pattern *l_pattern, va_list params)
{
	t_flag *l_flag;

	if (ft_is_indicateur(l_pattern->pattern[1]) == True)
	{
		l_pattern->indicateur = l_pattern->pattern[1];
		l_pattern->l_flag = NULL;
		get_arg(l_pattern, params);
		l_pattern->len = 2;
		return (True);
	}
	else if (ft_is_indicateur(l_pattern->pattern[1]) == False)
	{
		if (!(flag_init(&l_flag, &(l_pattern->pattern[1]), params)))
			return (False);
		pattern_add_flag(l_pattern, l_flag);
		l_pattern->indicateur = get_indicator(l_pattern->pattern);
		get_arg(l_pattern, params);
	}
	return(True);
}
