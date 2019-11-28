/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_free.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 12:12:22 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	pattern_free_one(t_pattern **l_pattern)
{
	if (!l_pattern)
		return ;
	(*l_pattern)->pattern = NULL;
	ft_memdel((void **)&((*l_pattern)->result));
	(*l_pattern)->result = NULL;
	ft_memdel((void **)&((*l_pattern)->varg));
	(*l_pattern)->result = NULL;
	// flag_free(&(*self)->t_flags);
	ft_memdel((void**) l_pattern);
	l_pattern = NULL;
}


void 	pattern_free(t_pattern **l_pattern)
{
	t_pattern *temp;

	while (*l_pattern)
	{
		temp = (*l_pattern)->next;
		pattern_free_one(l_pattern);
		*l_pattern = temp;
	}
	l_pattern = NULL;
}
