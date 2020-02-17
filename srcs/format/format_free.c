/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:27:02 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:27:04 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	format_free(t_format **s_format)
{
	ft_memdel((void **)&(*s_format)->format);
	(*s_format)->pointer_f = NULL;
	input_free(&((*s_format)->l_input));
	ft_memdel((void**)s_format);
}
