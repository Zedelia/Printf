/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:04:59 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 11:41:52 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char  *create_result_str_di(t_pattern *l_pattern)
{
	int  	width;
	int 	preci;
	char 	*copy_result;
	int len;

	copy_result = NULL;
	len = ft_strlen(l_pattern->result);
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (preci > width && preci > len)
	{
		preci = (ft_atoi(l_pattern->result) < 0 && l_pattern->indicator != 'u') ? preci + 1 : preci;
		copy_result = create_malloc(copy_result, preci);
	}
	else if (width == 0 && preci == 0)
		copy_result = create_malloc(copy_result, len);
	else if (width > len)
		copy_result = create_malloc(copy_result, width);
	else
		copy_result = create_malloc(copy_result, len);
	return (copy_result);
}

t_bool 	apply_diux(t_pattern *l_pattern)
{
	char *copy_result;

	if (!(copy_result = create_result_str_di(l_pattern)))
		return (false_ret(__func__));
	if (l_pattern->l_flag->type == '0' || l_pattern->l_flag->type == 'N')
	{
		if (!(apply_diux_zero(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	else if (l_pattern->l_flag->type == '-')
	{
		if (!(apply_diux_tiret(copy_result, l_pattern)))
			return (false_ret(__func__));
	}
	ft_memdel((void**)&copy_result);
	return (True);
}
