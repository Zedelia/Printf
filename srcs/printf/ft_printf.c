/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:41:43 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_format	*s_format;
	va_list		params;
	int			ret;

	init_get_fct_tab();
	va_start(params, s);
	if (!ft_isincharset('%', s))
	{
		ret = write(1, s, ft_strlen(s));
		return (ret);
	}
	if (!(format_init(&s_format, s, params)))
		return (-1);
	ret = 0;
	ret = put_output(s, s_format, ret);
	format_free(&s_format);
	va_end(params);
	return (ret);
}
