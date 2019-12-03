/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:12:50 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 14:55:03 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool apply_flag_tiret(char *copy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
    int precision;
	int i;
    int j;

	i = 0;
    j = 0;
    precision = 0;
	len = ft_strlen(l_pattern->result);
	width = *(int *)(l_pattern->l_flag->width);
    if (l_pattern->l_flag->precision)
		precision = *(int *)(l_pattern->l_flag->precision);
	while (i < precision - len)
		copy_result[i++] = '0';
	while ((l_pattern->result)[j])
		copy_result[i++] = (l_pattern->result)[j++];
    while (width - i > 0)
        copy_result[i++] = ' ';
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}

char 	*apply_zero_and_preci(char *copy_result, int precision, int width)
{
	if (precision)
	{
		while (precision  > 0 )
		{
			copy_result[width--] = '0';
			precision--;
		}
		while (width  >= 0)
			copy_result[width--] = ' ';
	}
	else if (!precision)
	{
		while (width  >= 0)
			copy_result[width--] = '0';
	}
	return (copy_result);
}

t_bool apply_flag_zero(char *copy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
	int precision;

	precision = 0;
	len = ft_strlen(l_pattern->result) - 1;
	width = *(int *)(l_pattern->l_flag->width);
	if (l_pattern->l_flag->precision)
		precision = *(int *)(l_pattern->l_flag->precision);
	while (len  >= 0)
	{
		copy_result[width--] = (l_pattern->result)[len--];
		precision--;
	}
	copy_result = apply_zero_and_preci(copy_result, precision, width);
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}

char  *create_result_str(t_pattern *l_pattern)
{
	int  width;
	int precision;
	char *copy_result;

	width = *(int *)(l_pattern->l_flag->width);
	precision = 0;
	if (l_pattern->l_flag->precision)
		precision = *(int *)(l_pattern->l_flag->precision);
	if (precision > width && l_pattern->l_flag->flag_type == '0')
		width = precision;
	if (!(copy_result = malloc(sizeof((char)*(&width)))))
		return (NULL);
	copy_result[width] = '\0';
	return (copy_result);
}

t_bool 	apply_flags(t_pattern *l_pattern)
{
	char *copy_result;

	if (!(copy_result = create_result_str(l_pattern)))
		return (false_ret(__func__));
	if (l_pattern->l_flag->flag_type == '0')
	{
		if (!(apply_flag_zero(copy_result, l_pattern)))
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
