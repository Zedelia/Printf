/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_init.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:39 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_init(t_input **l_input, char *format, va_list params)
{
	if (!(*l_input = malloc(sizeof(t_input))))
		return (False);
	(*l_input)->next = NULL;
	(*l_input)->len = 0;
	(*l_input)->output = NULL;
	(*l_input)->varg = NULL;
	(*l_input)->p_input = format;
	(*l_input)->l_flag = NULL;
	(*l_input)->input_cpy = NULL;
	if (!(input_parser(*l_input, params)))
		return (False);
	if (!(input_convert((*l_input))))
		return (False);
	return (True);
}
