/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:01:27 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

static t_bool error_format(t_format *self)
{
	ft_memdel((void **) &self->format);
	self->format = ft_strdup("(null)");
	return (False);
}

t_bool	format_init(t_format **self, const char *format, va_list params)
{
	if (!(*self = malloc(sizeof(t_format))))
		return (False);
	if (!((*self)->format = ft_strdup(format)))
		return (False);
	(*self)->l_pattern_conv = NULL;
	params = NULL;
	if (!(format_parser((*self)->format, params)))
		return (error_format(*self));
	return (True);
}
