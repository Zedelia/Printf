/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 19:50:36 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



int		ft_printf(const char *s, ...)
{
	t_format	*format;
	va_list		params;

	va_start(params, s);
	format_init(&format, s, params);
	write(1, format->format, ft_strlen(format->format));
	format_free(&format);
	return (0);
}
