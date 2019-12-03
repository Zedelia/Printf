/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_free.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 13:22:36 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	pattern_free_one(t_pattern **l_pattern)
{
	if (!l_pattern)
		return ;
	(*l_pattern)->p_pattern = NULL;
	ft_memdel((void **)&((*l_pattern)->pattern_cpy));
	(*l_pattern)->pattern_cpy = NULL;
	ft_memdel((void **)&((*l_pattern)->result));
	(*l_pattern)->result = NULL;
	ft_memdel((void **)&((*l_pattern)->varg));
	(*l_pattern)->result = NULL;
	if ((*l_pattern)->l_flag)
		flag_free(&(*l_pattern)->l_flag);
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
