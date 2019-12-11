/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_sc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:25:37 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:13:38 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool check_string(t_pattern *l_pattern)
{
	if (!(l_pattern->result = ft_strdup("(null)\n")))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_c(t_pattern *l_pattern)
{
	if (l_pattern->varg == NULL)
		return (check_string(l_pattern));
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
	if (l_pattern->varg == NULL)
		return (check_string(l_pattern));
	if (!(l_pattern->result = ft_strdup(((char *)l_pattern->varg))))
			return (false_ret(__func__));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_flags_cs(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
