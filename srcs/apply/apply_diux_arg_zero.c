/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diux_arg_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:13 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:40:00 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool	convert_zero(t_input *l_input)
{
	int i;

	if ((!(l_input->l_flag->width) || *(int *)(l_input->l_flag->width) == 0))
	{
		ft_memdel((void **)&l_input->output);
		if (!(l_input->output = malloc(sizeof(char))))
			return (false_ret(__func__));
		l_input->output[0] = '\0';
	}
	else
	{
		i = 0;
		if (!(apply_diux(l_input)))
			return (false_ret(__func__));
		while (l_input->output[i])
			l_input->output[i++] = ' ';
	}
	return (True);
}

static t_bool	check_zero_x(t_input *l_input)
{
	int len;

	len = ft_strlen((char *)l_input->varg);
	if (ft_strncmp("48", (const char *)l_input->varg, len))
	{
		ft_memdel((void **)&l_input->varg);
		if (!(l_input->varg = malloc(sizeof(unsigned int))))
			return (false_ret(__func__));
		*((int *)l_input->varg) = 0;
	}
	return (True);
}

t_bool			apply_diux_arg_zero(t_input *l_input)
{
	char *itoa;

	if (!(check_zero_x(l_input)))
		return (false_ret(__func__));
	if (l_input->output)
		ft_memdel((void *)&l_input->output);
	itoa = ft_itoa(*((int *)l_input->varg));
	if (!(l_input->output = ft_strdup(itoa)))
		return (false_ret(__func__));
	if (itoa)
		ft_memdel((void **)&itoa);
	if (l_input->l_flag->arg_weird == True)
		return (True);
	if (!(convert_zero(l_input)))
		return (false_ret(__func__));
	return (True);
}
