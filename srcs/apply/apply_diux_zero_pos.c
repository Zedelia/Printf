/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_zero_pos.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:01:10 by mbos        ###    #+. /#+    ###.fr     */
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
	if (l_pattern->l_flag->type == 'N')
	{
		while (width >= 0)
			cpy_result[width--] = ' ';
	}
	else if (l_pattern->l_flag->type == '0')
	{
		while (width >= 0)
			cpy_result[width--] = '0';
	}
	return (cpy_result);
}

static char 	*flag_zero_di_case3(t_pattern *l_pattern, int preci, int width, char *cpy_result)
{
	int len;
	int i;

	len = ft_strlen(l_pattern->result) - 1;
	width--;
	preci--;
	i = width < len ? len : width;
	while (len >= 0)
	{
		cpy_result[i--] = (l_pattern->result)[len--];
		preci--;
		width--;
	}
	while (preci >= 0)
	{
		cpy_result[i--] = '0';
		preci--;
		width--;
	}
	while (width >= 0)
		cpy_result[width--] = ' ';
	return (cpy_result);
}

t_bool		apply_diux_zero_pos(t_pattern *l_pattern, char *cpy_result)
{
	int width;
    int preci;

	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	if ((l_pattern->l_flag->preci) && preci > width)
		cpy_result = flag_zero_di_case1(l_pattern, preci, cpy_result);
	else if (!(l_pattern->l_flag->preci))
		cpy_result = flag_zero_di_case2(l_pattern, width, cpy_result);
	else if (preci <= width)
		cpy_result = flag_zero_di_case3(l_pattern, preci, width, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}
