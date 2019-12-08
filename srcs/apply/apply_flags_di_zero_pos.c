/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di_zero_pos.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:57:33 by melodieb     #+#   ##    ##    #+#       */
<<<<<<< HEAD
<<<<<<< HEAD:srcs/apply/apply_flags_di_zero.c
/*   Updated: 2019/12/05 00:24:11 by melodiebos  ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2019/12/05 17:49:21 by melodiebos  ###    #+. /#+    ###.fr     */
>>>>>>> temp-branch:srcs/apply/apply_flags_di_zero_pos.c
=======
/*   Updated: 2019/12/08 18:39:07 by melodiebos  ###    #+. /#+    ###.fr     */
>>>>>>> temp-branch
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_zero_di_case1(t_pattern *l_pattern, int preci, char *cpy_result)
{
	int len;
<<<<<<< HEAD

	len = ft_strlen(l_pattern->result);
	if (ft_atoi(l_pattern->result) < 0)
	{
		cpy_result[0] = '-';
		len--;
	}
	while (len >= 0)
		cpy_result[preci--] = (l_pattern->result)[len--];
	while (preci >= 0 )
		cpy_result[preci--] = '0';
=======
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
>>>>>>> temp-branch
	return (cpy_result);
}

static char 	*flag_zero_di_case2(t_pattern *l_pattern, int width, char *cpy_result)
{
	int len;

	len = ft_strlen(l_pattern->result);
<<<<<<< HEAD:srcs/apply/apply_flags_di_zero.c
	if (ft_atoi(l_pattern->result) < 0)
	{
		cpy_result[0] = '-';
		width--;
		len--;
	}
	while (len > 0)
=======
	width = (width > len) ? width : len;
	while (len >= 0)
>>>>>>> temp-branch:srcs/apply/apply_flags_di_zero_pos.c
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
	int i;

<<<<<<< HEAD
	len = ft_strlen(l_pattern->result);
<<<<<<< HEAD:srcs/apply/apply_flags_di_zero.c
	while (len > 0)
=======

=======
	len = ft_strlen(l_pattern->result) - 1;
	width--;
	preci--;
	i = width < len ? len : width;
>>>>>>> temp-branch
	while (len >= 0)
>>>>>>> temp-branch:srcs/apply/apply_flags_di_zero_pos.c
	{
		cpy_result[i--] = (l_pattern->result)[len--];
		preci--;
		width--;
	}
	while (preci >= 0)
	{
<<<<<<< HEAD
<<<<<<< HEAD:srcs/apply/apply_flags_di_zero.c
		cpy_result[width] = ft_atoi(l_pattern->result) < 0 ? '-' : '0';
		width = ft_atoi(l_pattern->result) < 0 ? width - 1 : width;
		while (width > 0)
			cpy_result[width--] = ' ';
	}
	else
	{
		while (preci > 0)
		{
			cpy_result[width--] = '0';
			preci--;
		}
		cpy_result[width] = ft_atoi(l_pattern->result) < 0 ? '-' : '0';
	width = ft_atoi(l_pattern->result) < 0 ? width - 1 : width;
		while (width > 0)
			cpy_result[width--] = ' ';
=======
		cpy_result[width--] = '0';
		preci--;
>>>>>>> temp-branch:srcs/apply/apply_flags_di_zero_pos.c
=======
		cpy_result[i--] = '0';
		preci--;
		width--;
>>>>>>> temp-branch
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
