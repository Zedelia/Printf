/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di_zero_neg.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 09:38:19 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:13:47 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_zero_di_case1(t_pattern *l_pattern, int preci, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
	cpy_result[0] = '-';
	len--;
	while (len > 0)
		cpy_result[preci--] = (l_pattern->result)[len--];
	while (preci > 0 )
		cpy_result[preci--] = '0';
	return (cpy_result);
}

static char 	*flag_zero_di_case2(t_pattern *l_pattern, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
	if (width < len)
		width = len;
	while (len > 0)
		cpy_result[width--] = (l_pattern->result)[len--];
	if (l_pattern->l_flag->flag_type == 'N')
	{
		cpy_result[width--] = '-';
		while (width >= 0)
			cpy_result[width--] = ' ';
	}
	else if (l_pattern->l_flag->flag_type == '0')
	{
		while (width > 0)
			cpy_result[width--] = '0';
		cpy_result[width--] = '-';
	}
	return (cpy_result);
}


static char 	*flag_zero_di_case3(t_pattern *l_pattern, int preci, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result) - 1;
	width = (width > len) ? width - 1 : width;
	{
		while (len > 0)
		{
			cpy_result[width--] = (l_pattern->result)[len--];
			preci--;
		}
		while (preci >= 0)
		{
			cpy_result[width--] = '0';
			preci--;
		}
	}
	while (len >= 0)
		cpy_result[width--] = (l_pattern->result)[len--];
	while (width >= 0)
			cpy_result[width--] = ' ';
	return (cpy_result);
}

t_bool apply_flag_di_zero_neg(t_pattern *l_pattern, char *cpy_result)
{
	int width;
    int preci;

	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	if (preci > width)
		cpy_result = flag_zero_di_case1(l_pattern, preci, cpy_result);
	else if (preci == 0)
		cpy_result = flag_zero_di_case2(l_pattern, width, cpy_result);
	else if (preci < width)
		cpy_result = flag_zero_di_case3(l_pattern, preci, width, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}
