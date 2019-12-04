/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_cs_tiret.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:23:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 11:27:49 by mbos        ###    #+. /#+    ###.fr     */
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
	preci = 0;
	width = *(int *)(l_pattern->l_flag->width);
	if (l_pattern->l_flag->precision)
		preci = *(int *)(l_pattern->l_flag->precision);
	while (preci && l_pattern->result[i])
	{
		copy_result[i] = l_pattern->result[i];
		i++;
		width--;
		preci--;
	}
	while (width)
	{
		copy_result[i++] = ' ';
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
	preci = 0;
	width = *(int *)(l_pattern->l_flag->width);
	if (l_pattern->l_flag->precision)
		preci = *(int *)(l_pattern->l_flag->precision);
	while (l_pattern->result[i])
	{
		copy_result[i] = l_pattern->result[i];
		i++;
		width--;
	}
	while (width)
	{
		copy_result[i++] = ' ';
		width--;
	}
	return (copy_result);
}


t_bool 		apply_flag_cs_tiret(t_pattern *l_pattern, char *copy_result)
{
    if (l_pattern->l_flag->precision)
		copy_result = flag_cs_tiret_case1(l_pattern, copy_result);
	else
		copy_result = flag_cs_tiret_case2(l_pattern, copy_result);

	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}
