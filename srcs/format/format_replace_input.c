/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_replace_pattern.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:02:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:08:54 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	format_replace_input(t_format *s_format)
{
	t_input	*temp;
	char		*format_tmp;
	char		*format_start;
	int 		i;

	if (!(format_tmp = ft_strdup(s_format->format)))
		return (false_ret(__func__));
	temp = s_format->l_input;
	i = 0;
	while (temp)
	{
		while (format_tmp[i] != '%')
			i++;
		if (!(format_start = ft_strndup(format_tmp, i)))
			return (false_ret(__func__));
		ft_memdel((void **)&format_tmp);
		if (!(format_tmp = ft_strjoin(format_start, temp->p_input)))
			return (false_ret(__func__));
		ft_memdel((void **)&format_start);
		i = i + ft_strlen(temp->output);
		temp = temp->next;
	}
	if (!(s_format->new_format = ft_strdup(format_tmp)))
		return (false_ret(__func__));
	return (True);
}
