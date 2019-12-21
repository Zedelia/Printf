/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_parser.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		format_add_input(t_format *s_format, t_input *l_input)
{
	t_input *temp;

	temp = s_format->l_input;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = l_input;
	}
	else
		s_format->l_input = l_input;
}

t_bool		format_parser(t_format *s_format, char *format, va_list params)
{
	t_input		*l_input;
	char		*cp_format;

	cp_format = format;
	if (format[0] == '%')
	{
		if (!(input_init(&l_input, cp_format, params)))
			return (False);
		format_add_input(s_format, l_input);
		cp_format = cp_format + l_input->len;
	}
	while (cp_format && (cp_format = ft_strchr(cp_format, '%')))
	{
		if (!(input_init(&l_input, cp_format, params)))
			return (False);
		format_add_input(s_format, l_input);
		cp_format = cp_format + l_input->len;
	}
	return (True);
}
