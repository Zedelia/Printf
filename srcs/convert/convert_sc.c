/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:20 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_c(t_input *l_input)
{
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
		return (false_ret(__func__));
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_cs(l_input)))
		return (false_ret(__func__));
	return (True);
}

t_bool	convert_s(t_input *l_input)
{
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
		return (false_ret(__func__));
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_cs(l_input)))
		return (false_ret(__func__));
	return (True);
}
