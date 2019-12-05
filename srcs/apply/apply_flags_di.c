/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:12:50 by melodieb     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2019/12/04 23:08:14 by melodiebos  ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2019/12/05 17:47:59 by melodiebos  ###    #+. /#+    ###.fr     */
>>>>>>> temp-branch
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char  *create_result_str_di(t_pattern *l_pattern)
{
	int  	width;
	int 	precision;
	char 	*copy_result;
	int len;

	copy_result = NULL;
	len = ft_strlen(l_pattern->result);
	precision = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (precision > width && precision > len)
	{
		precision = (ft_atoi(l_pattern->result) < 0 && l_pattern->indicateur != 'u') ? precision + 1 : precision;
		copy_result = create_malloc(copy_result, precision);
	}
	else if (width == 0 && precision == 0)
		copy_result = create_malloc(copy_result, len);
	else if (width > len)
		copy_result = create_malloc(copy_result, width);
	else
		copy_result = create_malloc(copy_result, len);
	return (copy_result);
}

static t_bool	apply_flag_di_zero(t_pattern *l_pattern, char *cpy_result)
{
	if (ft_atoi(l_pattern->result) < 0 && l_pattern->indicateur != 'u')
	{
		if (!(apply_flag_di_zero_neg(l_pattern, cpy_result)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_flag_di_zero_pos(l_pattern, cpy_result)))
			return (false_ret(__func__));
	}
	return (True);
}

t_bool 	apply_flags_di(t_pattern *l_pattern)
{
	char *copy_result;
	int width;
    int precision;

<<<<<<< HEAD
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	precision = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	copy_result = create_result_str_di(l_pattern);
=======
	if (!(copy_result = create_result_str_di(l_pattern)))
		return (false_ret(__func__));
>>>>>>> temp-branch
	if (l_pattern->l_flag->flag_type == '0' || l_pattern->l_flag->flag_type == 'N')
	{
		if (!(apply_flag_di_zero(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	else if (l_pattern->l_flag->flag_type == '-')
	{
		if (!(apply_flag_di_tiret(copy_result, l_pattern, precision, width)))
			return (false_ret(__func__));
	}
	ft_memdel((void**)&copy_result);
	return (True);
}
