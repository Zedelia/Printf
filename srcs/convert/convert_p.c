/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_p.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:29:14 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 21:33:49 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_p(t_pattern *l_pattern)
{
	int cmp;
	int len;

	len = ft_strlen((char *)l_pattern->varg);
	cmp = ft_strncmp("0x0", (const char *)l_pattern->varg, len);
	if (cmp == 0 && (l_pattern->l_flag->precision)
			&& *(int *)(l_pattern->l_flag->precision) == 0)
	{
		if (!(apply_diux_arg_zero(l_pattern)))
			return (false_ret(__func__));
		return (True);
	}
	if (!(l_pattern->result = ft_strdup(((char *)l_pattern->varg))))
			return (false_ret(__func__));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_diux(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
