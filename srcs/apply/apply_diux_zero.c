/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diux_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:37 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	apply_diux_zero(t_input *l_input, char *cpy_output)
{
	if (ft_atoi(l_input->output) < 0 && l_input->indicator != 'u')
	{
		if (!(apply_diux_zero_neg(l_input, cpy_output)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_diux_zero_pos(l_input, cpy_output)))
			return (false_ret(__func__));
	}
	return (True);
}
