/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_free.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:26:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	pattern_free_one(t_pattern **self)
{
	if (!self)
		return ;
	ft_memdel((void **)&(*self)->pattern);
	(*self)->pattern = NULL;
	ft_memdel((void **)&(*self)->result);
	(*self)->result = NULL;
	ft_memdel(self->varg);
	(*self)->varg = NULL;
	flag_free(&(*self)->l_flags);
	ft_memdel((void**) self);
	self = NULL;
}


void 	pattern_free(t_pattern **self)
{
	t_pattern *temp;

	if (!self)
		return ;
	while (*self)
	{
		temp = (*self)->next;
		ft_memdel((void **)&(*self)->pattern);
		(*self)->pattern = NULL;
		ft_memdel((void **)&(*self)->result);
		(*self)->result = NULL;
		ft_memdel(self->varg);
		(*self)->varg = NULL;
		flag_free(&(*self)->l_flags);
		ft_memdel((void**) self);
		self = temp;
	}
}
