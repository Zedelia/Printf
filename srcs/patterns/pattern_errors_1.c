/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_errors_1.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:03:11 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:03:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	error_several_flags(t_pattern *l_pattern)
{
	if (l_pattern->indicator != '%')
	{
		if (ft_isincharset('-', l_pattern->pattern_cpy)
				&& occur_before('0', l_pattern->pattern_cpy, '-') > 0)
			return (false_ret(__func__));
		if (ft_strchr(l_pattern->pattern_cpy, '-')
				&& ft_strchr(l_pattern->pattern_cpy, '-')[1] == '0')
			return (false_ret(__func__));
		if (occur_before('-', l_pattern->pattern_cpy, '.') > 1
				|| occur_after('-', l_pattern->pattern_cpy, '.') > 0)
			return (false_ret(__func__));
	}
	return (True);
}

t_bool	error_too_many_stars(t_pattern *l_pattern)
{
	if (occur_before('*', l_pattern->pattern_cpy, '.') > 1)
		return (false_ret(__func__));
	if (occur_after('*', l_pattern->pattern_cpy, '.') > 1)
		return (false_ret(__func__));
	return (True);
}

t_bool	error_zero_sc(t_pattern *l_pattern)
{
	if (l_pattern->pattern_cpy[0] == '0'
			&& (l_pattern->indicator == 's' || l_pattern->indicator == 'c'))
		return (false_ret(__func__));
	return (True);
}

t_bool	error_preci_cp(t_pattern *l_pattern)
{
	if (ft_isincharset('.', l_pattern->pattern_cpy) &&
		(l_pattern->indicator == 'c' || l_pattern->indicator == 'p'))
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
