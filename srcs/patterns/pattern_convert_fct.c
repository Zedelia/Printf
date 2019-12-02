/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_convert_fct.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:52:18 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 19:16:57 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool apply_width_left(t_pattern *l_pattern)
{
	char *copy_width;

	int width;
	int len;
	int i;

	width = *((int *)(l_pattern->l_flag->width));
	i = width;
	if (!(copy_width = malloc((char)*(&i + 1))))
		return (false_ret(__func__));
	while (copy_width)
		i++;
	while ((len = ft_strlen(l_pattern->result) >= 0))
	{
		copy_width[i] = l_pattern->result[len];
		i--;
		len--;
	}
	l_pattern->result = copy_width;
	return (True);
}

t_bool  convert_di(t_pattern *l_pattern)
{
	int 	len;
	int 	width;
	int precision;

	if (l_pattern->l_flag->precision)
		precision = *(int *)(l_pattern->l_flag->precision);
	if (l_pattern->l_flag->width)
		width = *(int *)(l_pattern->l_flag->width);
	l_pattern->result = ft_itoa(*((int *)l_pattern->varg));
	if (!(l_pattern->l_flag))
		return (True);
	len = ft_strlen(l_pattern->result);
	if (width > len && width > precision && l_pattern->l_flag->flag_type == '-')
		apply_width_left(l_pattern);

	return (True);
}

t_bool  convert_s(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_c(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_p(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_u(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_x(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}

t_bool  convert_percent(t_pattern *l_pattern)
{
	if(l_pattern)
		return (True);
	return (False);
}
