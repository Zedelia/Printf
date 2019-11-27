/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 17:52:49 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void init_get_fct_tab(void)
{
	g_get_fct[_c] = get_c;
	g_get_fct[_s] = get_s;
	g_get_fct[_p] = get_p;
	g_get_fct[_d] = get_di;
	g_get_fct[_i] = get_di;
	g_get_fct[_u] = get_u;
	g_get_fct[_x] = get_x;
	g_get_fct[_big_x] = get_x;
	g_get_fct[_percent] = get_percent;
}

int		ft_printf(const char *s, ...)
{
	t_format	*s_format;
	va_list		params;

	init_get_fct_tab();
	va_start(params, s);
	format_init(&s_format, s, params);
	write(1, s_format->format, ft_strlen(s_format->format));
	format_free(&s_format);
// a supprimer
	show_format(s_format);
	return (0);
}
