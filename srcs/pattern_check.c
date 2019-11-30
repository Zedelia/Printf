/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:26:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 15:44:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	error_several_flags(t_pattern *l_pattern)
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

t_bool	get_errors(t_pattern *l_pattern)
{
	size_t 				index;
	t_get_error_fct		*fonc;

	index = 0;
	while (index != errors_size)
	{
		fonc = g_get_error_fct[index];
		if (fonc(l_pattern) == False)
			return (false_ret(__func__));
		index++;
	}
	return (True);
}

void 	init_error_fct_tab(void)
{
	g_get_error_fct[_several_flags] = error_several_flags;
	g_get_error_fct[_too_many_stars] = error_too_many_stars;
	g_get_error_fct[_zero_sc] = error_zero_sc;
	g_get_error_fct[_precision_c] = error_precision_c;
	g_get_error_fct[_digit_stars_before_flag] = error_digit_stars_before_flag;
	g_get_error_fct[_digit_stars_together] = error_digit_stars_together;
}

t_bool	pattern_check(t_pattern *l_pattern)
{
	if (!(get_indicator(l_pattern)))
		return (false_ret(__func__));
	init_error_fct_tab();
	if (!(get_errors(l_pattern)))
		return (false_ret(__func__));

	return (True);
}

t_bool	pattern_copy(t_pattern *l_pattern)
{
	size_t n;

	n = 1;
	while (is_indicator(l_pattern->p_pattern[n]) == False)
		n++;
	if (!(l_pattern->pattern_cpy = ft_strndup(&(l_pattern->p_pattern[1]), n + 1)))
		return (false_ret(__func__));
	if (!(pattern_check(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
