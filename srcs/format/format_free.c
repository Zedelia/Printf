/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:00:58 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 12:47:24 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void format_free(t_format **s_format)
{
	ft_memdel((void **)&(*s_format)->format);
	(*s_format)->format = NULL;
	ft_memdel((void **)&(*s_format)->new_format);
	(*s_format)->new_format = NULL;
	pattern_free(&((*s_format)->l_pattern));
	ft_memdel((void**) s_format);
	s_format = NULL;
}
