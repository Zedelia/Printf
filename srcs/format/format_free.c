/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:00:58 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:07:39 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void format_free(t_format **s_format)
{
	ft_memdel((void **)&(*s_format)->format);
	(*s_format)->format = NULL;
	pattern_free(&((*s_format)->l_pattern));
	ft_memdel((void**) s_format);
	s_format = NULL;
}
