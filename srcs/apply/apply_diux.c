/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:42 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char		*create_output_str_diux(t_input *l_input)
{
	int		width;
	int		preci;
	char	*cpy_output;
	int		len;

	cpy_output = NULL;
	len = ft_strlen(l_input->output);
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	if (preci > width && preci > len)
	{
		if (ft_atoi(l_input->output) < 0 && l_input->indicator != 'u')
			preci += 1;
		cpy_output = create_malloc(cpy_output, preci);
	}
	else if (width == 0 && preci == 0)
		cpy_output = create_malloc(cpy_output, len);
	else if (width > len)
		cpy_output = create_malloc(cpy_output, width);
	else
		cpy_output = create_malloc(cpy_output, len);
	return (cpy_output);
}

t_bool			apply_diux(t_input *l_input)
{
	char *cpy_output;

	if (!(cpy_output = create_output_str_diux(l_input)))
		return (false_ret(__func__));
	if (l_input->l_flag->type == '0' || l_input->l_flag->type == 'N')
	{
		if (!(apply_diux_zero(l_input, cpy_output)))
			return (false_ret(__func__));
	}
	else if (l_input->l_flag->type == '-')
	{
		if (!(apply_diux_tiret(cpy_output, l_input)))
			return (false_ret(__func__));
	}
	ft_memdel((void**)&cpy_output);
	return (True);
}
