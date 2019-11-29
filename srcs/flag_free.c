/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 19:29:25 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:52:58 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	flag_free(t_flag **l_flag)
{
	if (!l_flag)
		return ;
	if ((*l_flag)->precision)
	{
		ft_memdel((void**)&((*l_flag)->precision));
		(*l_flag)->precision = NULL;
	}
	if ((*l_flag)->width)
	{
		ft_memdel((void**)&((*l_flag)->width));
		(*l_flag)->precision = NULL;
	}
	ft_memdel((void**) l_flag);
	l_flag = NULL;
}

// void 	flag_free(t_flag **l_flag)
// {
// 	t_flag *temp;
//
// 	while (*l_flag)
// 	{
// 		temp = (*l_flag)->next;
// 		flag_free_one(l_flag);
// 		*l_flag = temp;
// 	}
// 	l_flag = NULL;
// }
