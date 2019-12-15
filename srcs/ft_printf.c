/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 19:58:51 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 11:06:55 by melodiebos  ###    #+. /#+    ###.fr     */
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
	if (!ft_isincharset('%', s))
	{
		write(1, s, ft_strlen(s));
		return (0);
	}
	if (!(format_init(&s_format, s, params)))
		return (-1);
	write(1, s_format->new_format, ft_strlen(s_format->new_format));
	format_free(&s_format);
	va_end(params);
	return (0);
}
