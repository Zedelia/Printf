/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_parser.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 18:55:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 17:06:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	format_parser(t_format *s_format, char *format, va_list params)
{
	int i;
	t_pattern *l_pattern;

	l_pattern = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (!(pattern_init(&l_pattern, &format[i], params)))
				return (False);
			s_format->l_pattern = l_pattern;
		}
		i++;

	}
	return (True);
}
