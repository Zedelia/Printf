/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:27 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:36:23 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	count_char(char *string)
{
	int i;

	i = 0;
	while (string[i] && string[i] != '%')
		i++;
	return (i);
}

int 	check_char(t_input *temp, int ret)
{
	if (temp->output[0] == '\0' && temp->indicator == 'c')
	{
		ft_putchar('\0');
		ret += 1;
	}
	return (ret);
}

int 	put_output(const char *format, t_format *s_format, int ret)
{
	int i;
	t_input *temp;
	int j;

	j = 0;
	temp = s_format->l_input;
	while (format[j])
	{
		i = count_char(s_format->format);
		ret += write(1, s_format->format, i);
		if (temp)
		{
			ret = check_char(temp, ret);
			if (temp->output)
				ret += write(1, temp->output, ft_strlen(temp->output));
			s_format->format = s_format->format + i + temp->len;
			j += temp->len;
			temp = temp->next;
		}
		j += i;
	}
	return (ret);
}

int		ft_printf(const char *s, ...)
{
	t_format	*s_format;
	va_list		params;
	int 		ret;

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
