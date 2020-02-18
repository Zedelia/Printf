/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:06 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:37:32 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	apply_cs(t_input *l_input)
{
	if (l_input->l_flag->type == '-')
	{
		if (!(apply_cs_tiret(l_input)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_cs_none(l_input)))
			return (false_ret(__func__));
	}
	return (True);
}
