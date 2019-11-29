/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_parser.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 10:05:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:47:18 by mbos        ###    #+. /#+    ###.fr     */
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


	if (!(pattern_copy(l_pattern)))
		return (False);
	if (ft_is_indicateur(l_pattern->pattern_cpy[0]) == True)
	{
		l_pattern->indicateur = l_pattern->pattern_cpy[0];
		l_pattern->l_flag = NULL;
		get_arg(l_pattern, params);
		l_pattern->len = 2;
		return (True);
	}
	else if (ft_is_indicateur(l_pattern->pattern_cpy[0]) == False)
	{
		if (!(flag_init(&l_flag, &(l_pattern->pattern_cpy[0]), params)))
			return (False);
		pattern_add_flag(l_pattern, l_flag);
		l_pattern->indicateur = get_indicator(l_pattern->pattern_cpy);
		get_arg(l_pattern, params);
	}
	return(True);
}
