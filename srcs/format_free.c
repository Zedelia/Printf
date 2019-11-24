/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:00:58 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:25:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void format_free(t_format **self)
{
	ft_memdel((void **)&(*self)->format);
	(*self)->format = NULL;
	pattern_free((*self)->l_pattern);
	ft_memdel((void**) self);
	self = NULL;
}
