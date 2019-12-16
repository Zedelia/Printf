/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_free.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 15:38:48 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void format_free(t_format **s_format)
{
	ft_memdel((void **)&(*s_format)->format);
	ft_memdel((void **)&(*s_format)->new_format);
	input_free(&((*s_format)->l_input));
	ft_memdel((void**) s_format);
}
