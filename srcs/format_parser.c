/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_parser.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 18:55:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 18:33:05 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	format_parser(t_format *s_format, char *format, va_list params)
{
	int i;
	t_pattern *l_pattern;
	char *cp_format;

	i = 0;
	if ((cp_format = ft_strchr(format, "%")
	{
		if (!(pattern_init(&l_pattern, cp_format, params)))
			return (False);
		s_format->l_pattern = l_pattern;
		while (cp_format[i])
		{
			if (cp_format == '%')
			{
				if (!(pattern_init(&(l_pattern->next), &cp_format[i], params)))
					return (False);
				l_pattern = l_pattern->next;
			}
			i++;
		}
	}
	return (True);
}
