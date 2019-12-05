/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:08 by mbos         #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2019/12/04 22:27:58 by melodiebos  ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2019/12/05 08:47:29 by melodiebos  ###    #+. /#+    ###.fr     */
>>>>>>> temp-branch
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
<<<<<<< HEAD
		return(0);
=======
		return (0);
>>>>>>> temp-branch
	}
	if (!(format_init(&s_format, s, params)))
		return (-1);
	write(1, s_format->new_format, ft_strlen(s_format->new_format));
	format_free(&s_format);
	// show_format(s_format);
	return (0);
}
