/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_errors_1.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:18 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:14:20 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	error_several_flags(t_input *l_input)
{
	if (l_input->indicator != '%')
	{
		if (ft_isincharset('-', l_input->input_cpy)
				&& occur_before('0', l_input->input_cpy, '-') > 0)
			return (false_ret(__func__));
		if (ft_strchr(l_input->input_cpy, '-')
				&& ft_strchr(l_input->input_cpy, '-')[1] == '0')
			return (false_ret(__func__));
		if (occur_before('-', l_input->input_cpy, '.') > 1
				|| occur_after('-', l_input->input_cpy, '.') > 0)
			return (false_ret(__func__));
	}
	return (True);
}

t_bool	error_too_many_stars(t_input *l_input)
{
	if (occur_before('*', l_input->input_cpy, '.') > 1)
		return (false_ret(__func__));
	if (occur_after('*', l_input->input_cpy, '.') > 1)
		return (false_ret(__func__));
	return (True);
}

t_bool	error_zero_sc(t_input *l_input)
{
	if (l_input->input_cpy[0] == '0'
			&& (l_input->indicator == 's' || l_input->indicator == 'c'))
		return (false_ret(__func__));
	return (True);
}

t_bool	error_preci_cp(t_input *l_input)
{
	if (ft_isincharset('.', l_input->input_cpy) &&
		(l_input->indicator == 'c' || l_input->indicator == 'p'))
		return (false_ret(__func__));
	return (True);
}

t_bool	error_digit_stars_before_flag(t_input *l_input)
{
	if (ft_isincharset('-', l_input->input_cpy)
		&& (ft_isdigit(l_input->input_cpy[0])
						|| l_input->input_cpy[0] == '*'))
		return (false_ret(__func__));
	return (True);
}
