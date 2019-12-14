/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_replace_pattern.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:11:12 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 08:34:48 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	format_replace_pattern(t_format *s_format)
{
	t_pattern	*temp;
	char		*format_tmp;
	char		*format_start;
	int 		i;

	if (!(format_tmp = ft_strdup(s_format->format)))
		return (false_ret(__func__));
	temp = s_format->l_pattern;
	i = 0;
	while (temp)
	{
		while (format_tmp[i++] != '%')
		if (!(format_start = ft_strndup(format_tmp, i)))
			return (false_ret(__func__));
		ft_memdel((void **)&format_tmp);
		if (!(format_tmp = ft_strjoin(format_start, temp->p_pattern)))
			return (false_ret(__func__));
		ft_memdel((void **)&format_start);
		i = i + ft_strlen(temp->result);
		temp = temp->next;
	}
	if (!(s_format->new_format = ft_strdup(format_tmp)))
		return (false_ret(__func__));
	return (True);
}
