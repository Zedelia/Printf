/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_convert_fct.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodiebos <melodiebos@student.le-101.f    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:52:18 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 21:13:37 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_di(t_pattern *l_pattern)
{
	int 	width;
	int		precision;

	precision = 0;
	width = 0;
	if (l_pattern->l_flag->precision)
		precision = *(int *)(l_pattern->l_flag->precision);
	if (l_pattern->l_flag->width)
		width = *(int *)(l_pattern->l_flag->width);
	// if (precision && width && precision > width)
	// {
	// 	if (!(apply_precision(l_pattern)))
	// 		return (false_ret(__func__));
	// 	return (True);
	// }
	l_pattern->result = ft_itoa(*((int *)l_pattern->varg));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_flags(l_pattern)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_s(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_c(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_p(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_u(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_x(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_percent(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}
