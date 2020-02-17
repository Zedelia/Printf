/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:37 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	flag_init(t_flag **l_flag, char *flags, va_list params)
{
	if (!(*l_flag = malloc(sizeof(t_flag))))
		return (false_ret(__func__));
	(*l_flag)->preci = NULL;
	(*l_flag)->width = NULL;
	(*l_flag)->arg_weird = False;
	if (!(flag_parser(*l_flag, flags, params)))
		return (false_ret(__func__));
	return (True);
}
