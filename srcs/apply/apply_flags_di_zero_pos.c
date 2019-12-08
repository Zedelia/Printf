/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di_zero_pos.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:57:33 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 17:05:29 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_zero_di_case1(t_pattern *l_pattern, int preci, char *cpy_result)
{
	int len;
	int i;
	len = ft_strlen(l_pattern->result) - 1;
	i = len > preci ? len : preci - 1;
	while (len  >= 0)
	{
		cpy_result[i] = (l_pattern->result)[len];
		preci--;
		len--;
		i--;
	}
	while (preci >= 0)
	{
		cpy_result[i--] = '0';
		preci--;
	}
	return (cpy_result);
}

static char 	*flag_zero_di_case2(t_pattern *l_pattern, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
	width = (width > len) ? width : len;
	while (len >= 0)
		cpy_result[width--] = (l_pattern->result)[len--];
	if (l_pattern->l_flag->flag_type == 'N')
	{
		while (width >= 0)
			cpy_result[width--] = ' ';
	}
	else if (l_pattern->l_flag->flag_type == '0')
	{
		while (width >= 0)
			cpy_result[width--] = ' ';
	}
	return (cpy_result);
}

static char 	*flag_zero_di_case3(t_pattern *l_pattern, int preci, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);

	while (len >= 0)
	{
		cpy_result[width--] = (l_pattern->result)[len--];
		preci--;
	}
	while (preci >= 0)
	{
		cpy_result[width--] = '0';
		preci--;
	}
	while (width >= 0)
		cpy_result[width--] = ' ';
	return (cpy_result);
}

t_bool		apply_flag_di_zero_pos(t_pattern *l_pattern, char *cpy_result)
{
	int width;
    int preci;

	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	if (preci > width)
		cpy_result = flag_zero_di_case1(l_pattern, preci, cpy_result);
	else if (preci == 0)
		cpy_result = flag_zero_di_case2(l_pattern, width, cpy_result);
	else if (preci <= width)
		cpy_result = flag_zero_di_case3(l_pattern, preci, width, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}
