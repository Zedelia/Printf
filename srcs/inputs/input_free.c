/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_free.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:39:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	input_free_one(t_input **l_input)
{
	if (!l_input)
		return ;
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
