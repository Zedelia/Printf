/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs_tiret.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:23:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 19:31:20 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_cs_tiret_case1(t_pattern *l_pattern, char *copy_result)
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
		width--;
		preci--;
	}
	while (width > 0)
	{
		copy_result[i] = ' ';
		i++;
		width--;
	}
	return (copy_result);
}

static char 	*flag_cs_tiret_case2(t_pattern *l_pattern, char* copy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	while (l_pattern->result[i])
	{
		copy_result[i] = l_pattern->result[i];
		i++;
		width--;
	}
	while (width > 0)
	{
		copy_result[i] = ' ';
		i++;
		width--;
	}
	return (copy_result);
}


t_bool 		apply_cs_tiret(t_pattern *l_pattern, char *copy_result)
{
    if (l_pattern->l_flag->precision)
		copy_result = flag_cs_tiret_case1(l_pattern, copy_result);
	else
		copy_result = flag_cs_tiret_case2(l_pattern, copy_result);
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}
