/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 18:05:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_format	*s_format;
	va_list		params;
	int i;

	init_get_fct_tab();
	va_start(params, s);
	if (!ft_isincharset('%', s))
	{
		i = write(1, s, ft_strlen(s));
		return (i);
	}
	if (!(format_init(&s_format, s, params)))
		return (-1);
	// i = write(1, s_format->new_format, s_format->full_len_newformat);
	i = write(1, s_format->new_format, ft_strlen(s_format->new_format));
	format_free(&s_format);
	va_end(params);
	return (i);
}
