/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sc_create_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:25:53 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:25:55 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*create_output_str_sc(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int len;
	int size;

	len = ft_strlen(l_input->output);
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	if (preci > 0 && width > len)
		size = width;
	else if (!(l_input->l_flag->preci) && width < len)
		size = len;
	else if (preci >= 0 && width > preci)
		size = width;
	else if (preci < 0)
		size = width > len ? width : len;
	else if (preci >= 0 && preci < len)
		size = preci;
	else
		size = len;
	if (!(cpy_output = ft_calloc((size + 1), sizeof(char))))
		return (NULL);
	return (cpy_output);
}
