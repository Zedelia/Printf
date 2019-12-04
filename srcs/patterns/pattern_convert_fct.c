/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_convert_fct.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:52:18 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 12:38:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_di(t_pattern *l_pattern)
{
	l_pattern->result = ft_itoa(*((int *)l_pattern->varg));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_flags_di(l_pattern)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_c(t_pattern *l_pattern)
{
	if (!(l_pattern->result = ft_strdup(((char *)l_pattern->varg))))
			return (false_ret(__func__));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_flags_cs(l_pattern)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_s(t_pattern *l_pattern)
{
	if (!(l_pattern->result = ft_strdup(((char *)l_pattern->varg))))
			return (false_ret(__func__));
	if (!(l_pattern->l_flag))
		return (True);

	if (!(apply_flags_cs(l_pattern)))
		return (false_ret(__func__));
	return (True);
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
