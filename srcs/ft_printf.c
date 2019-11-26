/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 14:02:12 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



int		ft_printf(const char *s, ...)
{
	t_format	*s_format;
	va_list		params;

	va_start(params, s);
	format_init(&s_format, s, params);
	write(1, s_format->format, ft_strlen(s_format->format));
	format_free(&s_format);
// a supprimer
	show_format(s_format);
	return (0);
}
