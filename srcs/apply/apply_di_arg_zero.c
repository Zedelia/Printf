/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_di_arg_zero.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 11:22:51 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 16:50:22 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool 	convert_zero(t_pattern *l_pattern)
{
	if (!(l_pattern->result = malloc(sizeof(char))))
		return (false_ret(__func__));
	l_pattern->result[0] = '\0';
	return (True);
}

t_bool	apply_di_arg_zero(t_pattern *l_pattern)
{
	int i;

	i = 0;
	l_pattern->result = ft_itoa(*((int *)l_pattern->varg));
	if ((!(l_pattern->l_flag->width) || *(int *)(l_pattern->l_flag->width) == 0))
	{
		if (!(convert_zero(l_pattern)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_di(l_pattern)))
			return (false_ret(__func__));
		while(l_pattern->result[i])
			l_pattern->result[i++] = ' ';
	}
	return (True);
}
