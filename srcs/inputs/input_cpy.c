/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:27:27 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_cpy(t_input *l_input)
{
	size_t n;

	n = 1;
	while (is_indicator(l_input->p_input[n]) == False)
		n++;
	if (!(l_input->input_cpy = ft_strndup(&(l_input->p_input[1]), n)))
		return (false_ret(__func__));
	if (!(input_indicator(l_input)))
		return (false_ret(__func__));
	return (True);
}
