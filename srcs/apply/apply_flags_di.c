/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:12:50 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 18:59:27 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char  *create_result_str_di(t_pattern *l_pattern)
{
	int  width;
	int precision;
	char *copy_result;

	precision = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (precision > width)
	{
		if (!(copy_result = malloc(sizeof(char)*(precision + 1))))
			return (NULL);
		copy_result[precision] = '\0';
	}
	else
	{
		if (!(copy_result = malloc(sizeof(char)*(width + 1))))
			return (NULL);
		copy_result[width] = '\0';
	}
	return (copy_result);
}

t_bool 	apply_flags_di(t_pattern *l_pattern)
{
	char *copy_result;

	copy_result = create_result_str_di(l_pattern);
	if (l_pattern->l_flag->flag_type == '0' || l_pattern->l_flag->flag_type == 'N')
	{
		if (!(apply_flag_di_zero(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	if (l_pattern->l_flag->flag_type == '-')
	{
		if (!(apply_flag_di_tiret(copy_result, l_pattern)))
			return (false_ret(__func__));
	}
	ft_memdel((void**)&copy_result);
	return (True);
}
