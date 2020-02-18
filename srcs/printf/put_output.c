/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:28:16 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:28:17 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		count_char(char *string)
{
	int i;

	i = 0;
	while (string[i] && string[i] != '%')
		i++;
	return (i);
}

static int		check_char(t_input *temp, int ret)
{
	if (temp->output[0] == '\0' && temp->indicator == 'c')
	{
		ft_putchar('\0');
		ret += 1;
	}
	return (ret);
}

int				put_output(const char *format, t_format *s_format, int ret)
{
	int			i;
	t_input		*temp;
	int			j;

	j = 0;
	temp = s_format->l_input;
	while (format[j])
	{
		i = count_char(s_format->pointer_f);
		ret += write(1, s_format->pointer_f, i);
		if (temp)
		{
			ret = check_char(temp, ret);
			if (temp->output)
				ret += write(1, temp->output, ft_strlen(temp->output));
			s_format->pointer_f = s_format->pointer_f + i + temp->len;
			j += temp->len;
			temp = temp->next;
		}
		j += i;
	}
	return (ret);
}
