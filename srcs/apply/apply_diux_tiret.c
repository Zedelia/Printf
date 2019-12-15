/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_tiret.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:55:59 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 11:39:44 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"


static t_bool 	apply_diux_tiret_neg(char *cpy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
	int preci;
	int i;
	int j;

	i = 0;
    j = 0;
	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	cpy_result[i++] = '-';
	j++;
	len--;
	while (i <= preci - len)
		cpy_result[i++] = '0';
	while ((l_pattern->result)[j])
		cpy_result[i++] = (l_pattern->result)[j++];
    while (width - i > 0)
        cpy_result[i++] = ' ';
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}


static t_bool 	apply_diux_tiret_pos(char *cpy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
	int preci;
	int i;
	int j;

	i = 0;
	j = 0;
	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	while (i < preci - len)
		cpy_result[i++] = '0';
	while ((l_pattern->result)[j])
		cpy_result[i++] = (l_pattern->result)[j++];
	while (width - i > 0)
		cpy_result[i++] = ' ';
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}

t_bool apply_diux_tiret(char *cpy_result, t_pattern *l_pattern)
{
	if (ft_atoi(l_pattern->result) < 0 && l_pattern->indicator != 'u')
	{
		if (!(apply_diux_tiret_neg(cpy_result, l_pattern)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_diux_tiret_pos(cpy_result, l_pattern)))
			return (false_ret(__func__));
	}
	return (True);
}
