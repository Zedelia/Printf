/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:27:32 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:27:33 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	input_free_one(t_input **l_input)
{
	if (!l_input)
		return ;
	(*l_input)->p_input = NULL;
	ft_memdel((void **)&((*l_input)->input_cpy));
	ft_memdel((void **)&((*l_input)->output));
	ft_memdel((void **)&((*l_input)->varg));
	if ((*l_input)->l_flag)
		flag_free(&(*l_input)->l_flag);
	ft_memdel((void**)l_input);
	l_input = NULL;
}

void	input_free(t_input **l_input)
{
	t_input *temp;

	while (*l_input)
	{
		temp = (*l_input)->next;
		input_free_one(l_input);
		*l_input = temp;
	}
	l_input = NULL;
}
