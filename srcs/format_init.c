/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 17:07:34 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

static t_bool error_format(t_format *s_format)
{
	ft_memdel((void **) &s_format->format);
	s_format->format = ft_strdup("(null)");
	return (False);
}

t_bool	format_init(t_format **s_format, const char *format, va_list params)
{
	if (!(*s_format = malloc(sizeof(t_format))))
		return (False);
	if (!((*s_format)->format = ft_strdup(format)))
		return (False);
	(*s_format)->l_pattern = NULL;
	if (!(format_parser(*s_format, (*s_format)->format, params)))
		return (error_format(*s_format));
	return (True);
}
