/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:26:31 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:26:33 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flag_free(t_flag **l_flag)
{
	if (!l_flag)
		return ;
	if ((*l_flag)->preci)
	{
		ft_memdel((void**)&((*l_flag)->preci));
		(*l_flag)->preci = NULL;
	}
	if ((*l_flag)->width)
	{
		ft_memdel((void**)&((*l_flag)->width));
		(*l_flag)->preci = NULL;
	}
	ft_memdel((void**)l_flag);
	l_flag = NULL;
}
