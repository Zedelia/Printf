/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_sc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:01:43 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool check_string(t_pattern *l_pattern)
{
	if (!(l_pattern->result = ft_strdup("(null)")))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_c(t_pattern *l_pattern)
{
	if (ft_strncmp((const char *)l_pattern->varg, STRING_NULL, 6) == 0)
		return (check_string(l_pattern));
	if (!(l_pattern->result = ft_strdup(((char *)l_pattern->varg))))
			return (false_ret(__func__));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_cs(l_pattern)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_s(t_pattern *l_pattern)
{
	if (!(l_pattern->result = ft_strdup(((char *)l_pattern->varg))))
			return (false_ret(__func__));
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_cs(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
