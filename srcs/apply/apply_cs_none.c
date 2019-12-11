/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs_none.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:50:08 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 19:26:29 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_cs_none_case1(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	while (preci && l_pattern->result[i])
	{
		copy_result[i] = l_pattern->result[i];
		i++;
		preci--;
	}
	return (copy_result);
}


static char 	*flag_cs_none_case2(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int preci;
	int i;
	int j;

	i = 0;
	j = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	if (preci > 0)
	{
		while (width - preci > 0)
		{
			copy_result[i++] = ' ';
			width--;
		}
		while (preci > 0)
		{
			copy_result[i++] = l_pattern->result[j++];
			preci--;
		}
	}
	return (copy_result);
}

static char 	*flag_cs_none_case3(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (width > len)
	{
		while (width - len > 0)
		{
			copy_result[i++] = ' ';
			width--;
		}
	}
	while (l_pattern->result[j])
		copy_result[i++] = l_pattern->result[j++];
	return (copy_result);
}

static char		*flag_cs_none_case4(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	while (width > 0)
	{
		copy_result[i++] = ' ';
		width--;
	}
	return (copy_result);
}


t_bool 		apply_cs_none(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	if (preci > width)
		copy_result = flag_cs_none_case1(l_pattern, copy_result);
	else if (preci)
		copy_result = flag_cs_none_case2(l_pattern, copy_result);
	else if (l_pattern->l_flag->precision && preci == 0)
		copy_result = flag_cs_none_case4(l_pattern, copy_result);
	else
		copy_result = flag_cs_none_case3(l_pattern, copy_result);
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}
