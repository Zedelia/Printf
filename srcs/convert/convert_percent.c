/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:12 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_percent(t_input *l_input)
{
	if (!(l_input->output = malloc(sizeof(char) * 2)))
		return (false_ret(__func__));
	l_input->output[0] = l_input->indicator;
	l_input->output[1] = '\0';
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_percent(l_input)))
		return (false_ret(__func__));
	return (True);
}
