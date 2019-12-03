/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:12:50 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 16:01:09 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char  *create_result_str(t_pattern *l_pattern)
{
	int  width;
	int precision;
	char *copy_result;

	precision = 0;
	if (l_pattern->l_flag->precision)
		precision = *(int *)(l_pattern->l_flag->precision);
	width = *(int *)(l_pattern->l_flag->width);
	if (precision > width)
	{
		if (!(copy_result = malloc(sizeof(char)*(precision))))
			return (NULL);
		copy_result[precision] = '\0';
	}
	else
	{
		if (!(copy_result = malloc(sizeof(char)*(width))))
			return (NULL);
		copy_result[width] = '\0';
	}
	return (copy_result);
}

t_bool 	apply_flags(t_pattern *l_pattern)
{
	char *copy_result;

	copy_result = create_result_str(l_pattern);
	if (l_pattern->l_flag->flag_type == '0')
	{
		if (!(apply_flag_zero(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	if (l_pattern->l_flag->flag_type == '-')
	{
		if (!(apply_flag_tiret(copy_result, l_pattern)))
			return (false_ret(__func__));
	}
	ft_memdel((void**)&copy_result);
	return (True);
}
