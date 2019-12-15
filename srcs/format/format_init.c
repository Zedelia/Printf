/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:34 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:02:35 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	format_init(t_format **s_format, const char *format, va_list params)
{
	if (!(*s_format = malloc(sizeof(t_format))))
		return (false_ret(__func__));
	if (!((*s_format)->format = ft_strdup(format)))
		return (false_ret(__func__));
	(*s_format)->l_pattern = NULL;
	(*s_format)->new_format = NULL;
	if (!(format_parser(*s_format, (*s_format)->format, params)))
		return (false_ret(__func__));
	return (True);
}
