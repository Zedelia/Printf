/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:26 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_x(t_input *l_input)
{
	int cmp;
	int len;

	len = ft_strlen((char *)l_input->varg);
	cmp = ft_strncmp("0", (const char *)l_input->varg, len);
	if ((l_input->l_flag) && cmp == 0 && (l_input->l_flag->preci)
			&& *(int *)(l_input->l_flag->preci) == 0)
	{
		if (!(apply_diux_arg_zero(l_input)))
			return (false_ret(__func__));
		return (True);
	}
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
		return (false_ret(__func__));
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_diux(l_input)))
		return (false_ret(__func__));
	return (True);
}
