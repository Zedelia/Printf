/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodiebos <melodiebos@student.le-101.f    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 21:12:50 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 21:26:04 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool apply_width_tiret(char *copy_width, t_pattern *l_pattern)
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
		copy_width[i++] = '0';
	while ((l_pattern->result)[j])
		copy_width[i++] = (l_pattern->result)[j++];
    while (width - i > 0)
        copy_width[i++] = ' ';
	if (!(l_pattern->result = ft_strdup(copy_width)))
		return (false_ret(__func__));
	return (True);
}

t_bool apply_width_zero(char *copy_width, t_pattern *l_pattern)
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
		copy_width[width--] = (l_pattern->result)[len--];
		precision--;
	}
	while (precision  > 0 )
	{
		copy_width[width--] = '0';
		precision--;
	}
	while (width  >= 0)
		copy_width[width--] = ' ';
	if (!(l_pattern->result = ft_strdup(copy_width)))
		return (false_ret(__func__));
	return (True);
}

t_bool 	apply_flags(t_pattern *l_pattern)
{
	char *copy_width;
	int width;
	int len;

	width = *(int *)(l_pattern->l_flag->width);
	len = ft_strlen(l_pattern->result) - 1;
	if (!(copy_width = malloc(sizeof((char)*(&width)))))
		return (false_ret(__func__));
	copy_width[width] = '\0';
	if (l_pattern->l_flag->flag_type == '0')
	{
		if (!(apply_width_zero(copy_width, l_pattern)))
			return (false_ret(__func__));
	}
	if (l_pattern->l_flag->flag_type == '-')
	{
		if (!(apply_width_tiret(copy_width, l_pattern)))
			return (false_ret(__func__));
	}
	return (True);
}