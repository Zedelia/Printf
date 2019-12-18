/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 19:29:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:34:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
