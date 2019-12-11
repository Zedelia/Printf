/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_x.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 20:21:04 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 20:48:53 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_x(t_pattern *l_pattern)
{
	int cmp;
	int len;

	len = ft_strlen((char *)l_pattern->varg);
	cmp = ft_strncmp("0", (const char *)l_pattern->varg, len);
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
