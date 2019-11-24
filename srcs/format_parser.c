/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_parser.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 18:55:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:02:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	format_parser(char *format, va_list params)
{
	int i;
	t_pattern *pattern;

	pattern = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (!(pattern_init(&pattern, &format[i], params)))
				return (False);
		}
		i++;
	}

}
