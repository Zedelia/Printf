/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_tiret.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:55:59 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 19:25:59 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"


static t_bool 	apply_diux_tiret_neg(char *copy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
	int precision;
	int i;
	int j;

	i = 0;
    j = 0;
	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	precision = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	copy_result[i++] = '-';
	j++;
	len--;
	while (i <= precision - len)
		copy_result[i++] = '0';
	while ((l_pattern->result)[j])
		copy_result[i++] = (l_pattern->result)[j++];
    while (width - i > 0)
        copy_result[i++] = ' ';
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}


static t_bool 	apply_diux_tiret_pos(char *copy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
	int precision;
	int i;
	int j;

	i = 0;
	j = 0;
	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	precision = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
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

t_bool apply_diux_tiret(char *copy_result, t_pattern *l_pattern)
{
	if (ft_atoi(l_pattern->result) < 0 && l_pattern->indicateur != 'u')
	{
		if (!(apply_diux_tiret_neg(copy_result, l_pattern)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_diux_tiret_pos(copy_result, l_pattern)))
			return (false_ret(__func__));
	}
	return (True);
}