/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 18:46:35 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_format	*s_format;
	va_list		params;

	init_get_fct_tab();
	va_start(params, s);
	if (!(format_init(&s_format, s, params)))
		return (-1);
	write(1, s_format->new_format, ft_strlen(s_format->new_format));
	format_free(&s_format);
	show_format(s_format);
	return (0);
}
