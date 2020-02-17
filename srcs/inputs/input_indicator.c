/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_indicator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:27:51 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_indicator(t_input *l_input)
{
	if (!(get_indicator(l_input)))
		return (false_ret(__func__));
	return (True);
}
