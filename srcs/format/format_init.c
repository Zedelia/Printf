/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	format_init(t_format **s_format, const char *format, va_list params)
{
	if (!(*s_format = malloc(sizeof(t_format))))
		return (False);
	if (!((*s_format)->format = ft_strdup(format)))
		return (False);
	(*s_format)->l_input = NULL;
	if (!(format_parser(*s_format, (*s_format)->format, params)))
		return (False);
	(*s_format)->pointer_f = (*s_format)->format;
	return (True);
}
