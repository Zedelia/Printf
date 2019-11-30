/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_errors_2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:47:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:08:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	error_digit_stars_together(t_pattern *l_pattern)
{
	int i;

	i = 0;
	if ((ft_isincharset('.', l_pattern->pattern_cpy)
		&& occurence_before('*', l_pattern->pattern_cpy, '.') == 1))
	{
		while (l_pattern->pattern_cpy[i] != '.')
		{
			if (ft_isdigit(l_pattern->pattern_cpy[i]))
				return (false_ret(__func__));
			i++;
		}
	}
	if ((ft_isincharset('.', l_pattern->pattern_cpy)
		&& occurence_after('*', l_pattern->pattern_cpy, '.') == 1))
	{
		while (l_pattern->pattern_cpy[i] != '.')
		{
			if (ft_isdigit(l_pattern->pattern_cpy[i]))
				return (false_ret(__func__));
			i++;
		}
	}
	return (True);
}
