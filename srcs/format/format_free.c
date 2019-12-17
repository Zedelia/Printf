/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 16:11:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void format_free(t_format **s_format)
{
	ft_memdel((void **)&(*s_format)->format);
	(*s_format)->pointer_f = NULL;
	input_free(&((*s_format)->l_input));
	ft_memdel((void**) s_format);
}
