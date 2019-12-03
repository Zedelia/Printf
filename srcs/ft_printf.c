/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 14:02:17 by melodiebos  ###    #+. /#+    ###.fr     */
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
	format_init(&s_format, s, params);
	write(1, s_format->new_format, ft_strlen(s_format->new_format));
	format_free(&s_format);
	return (0);
}
