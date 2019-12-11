/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_errors_1.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:46:58 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 17:44:17 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	error_several_flags(t_pattern *l_pattern)
{
	if (l_pattern->indicateur != '%')
	{
		if (ft_isincharset('-', l_pattern->pattern_cpy)
				&& occurence_before('0', l_pattern->pattern_cpy, '-') > 0)
			return (false_ret(__func__));
		if (ft_strchr(l_pattern->pattern_cpy, '-')
				&& ft_strchr(l_pattern->pattern_cpy, '-')[1] == '0')
			return (false_ret(__func__));
		if (occurence_before('-', l_pattern->pattern_cpy, '.') > 1
				|| occurence_after('-', l_pattern->pattern_cpy, '.') > 0)
			return (false_ret(__func__));
	}
	return (True);
}

t_bool	error_too_many_stars(t_pattern *l_pattern)
{
	if (occurence_before('*', l_pattern->pattern_cpy, '.') > 1)
		return (false_ret(__func__));
	if (occurence_after('*', l_pattern->pattern_cpy, '.') > 1)
		return (false_ret(__func__));
	return (True);
}

t_bool	error_zero_sc(t_pattern *l_pattern)
{
	if (l_pattern->pattern_cpy[0] == '0'
			&& (l_pattern->indicateur == 's' || l_pattern->indicateur == 'c'))
		return (false_ret(__func__));
	return (True);
}

t_bool	error_precision_c(t_pattern *l_pattern)
{
	if (ft_isincharset('.', l_pattern->pattern_cpy) && l_pattern->indicateur == 'c')
		return (false_ret(__func__));
	return (True);
}

t_bool	error_digit_stars_before_flag(t_pattern *l_pattern)
{
	if (ft_isincharset('-', l_pattern->pattern_cpy)
		&& (ft_isdigit(l_pattern->pattern_cpy[0])
						|| l_pattern->pattern_cpy[0] == '*'))
		return (false_ret(__func__));
	return (True);
}
