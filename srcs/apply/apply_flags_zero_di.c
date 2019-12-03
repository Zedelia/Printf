/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_zero_di.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:57:33 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 16:21:30 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char 	*flag_zero_di_case1(t_pattern *l_pattern, int preci, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
	while (len  >= 0)
		cpy_result[preci--] = (l_pattern->result)[len--];
	while (preci  > 0 )
	{
		cpy_result[preci--] = '0';
		width--;
	}
	while (width  >= 0)
		cpy_result[width--] = ' ';
	return (cpy_result);
}

char 	*flag_zero_di_case2(t_pattern *l_pattern, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
	while (len >= 0)
		cpy_result[width--] = (l_pattern->result)[len--];
	while (width >= 0)
		cpy_result[width--] = '0';
	return (cpy_result);
}

char 	*flag_zero_di_case3(t_pattern *l_pattern, int preci, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
	while (len >= 0)
	{
		cpy_result[width--] = (l_pattern->result)[len--];
		preci--;
	}
	if (preci <= 0)
	{
		while (width >= 0)
			cpy_result[width--] = ' ';
	}
	else
	{
		while (preci > 0)
		{
			cpy_result[width--] = '0';
			preci--;
		}
		while (width >= 0)
			cpy_result[width--] = ' ';
	}
	return (cpy_result);
}

t_bool apply_flag_zero(t_pattern *l_pattern, char *cpy_result)
{
	int width;
    int preci;

    preci = 0;
	width = *(int *)(l_pattern->l_flag->width);
    if (l_pattern->l_flag->precision)
		preci = *(int *)(l_pattern->l_flag->precision);
	if (preci > width)
		cpy_result = flag_zero_di_case1(l_pattern, preci, width, cpy_result);
	else if (preci == 0)
		cpy_result = flag_zero_di_case2(l_pattern, width, cpy_result);
	else if (preci < width)
		cpy_result = flag_zero_di_case3(l_pattern, preci, width, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}
