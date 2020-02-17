/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:04:06 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	init_get_fct_tab(void)
{
	g_get_fct[_c] = get_c;
	g_get_fct[_s] = get_s;
	g_get_fct[_p] = get_p;
	g_get_fct[_d] = get_di;
	g_get_fct[_i] = get_di;
	g_get_fct[_u] = get_di;
	g_get_fct[_x] = get_x;
	g_get_fct[_big_x] = get_big_x;
	g_get_fct[_percent] = get_percent;
}

t_bool	get_arg(t_input *l_input, va_list params)
{
	t_get_fct	*fonc;
	size_t		index;

	index = ft_index(l_input->indicator, INDICATORS);
	fonc = g_get_fct[index];
	l_input->varg = fonc(params);
	if (!(l_input->varg))
		return (false_ret(__func__));
	return (True);
}
