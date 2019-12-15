/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs_tiret.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:35 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:00:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_cs_tiret_case1(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	while (preci && l_pattern->result[i])
	{
		cpy_result[i] = l_pattern->result[i];
		i++;
		width--;
		preci--;
	}
	while (width > 0)
	{
		cpy_result[i] = ' ';
		i++;
		width--;
	}
	return (cpy_result);
}

static char 	*flag_cs_tiret_case2(t_pattern *l_pattern, char* cpy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	while (l_pattern->result[i])
	{
		cpy_result[i] = l_pattern->result[i];
		i++;
		width--;
	}
	while (width > 0)
	{
		cpy_result[i] = ' ';
		i++;
		width--;
	}
	return (cpy_result);
}


t_bool 		apply_cs_tiret(t_pattern *l_pattern, char *cpy_result)
{
    if (l_pattern->l_flag->preci)
		cpy_result = flag_cs_tiret_case1(l_pattern, cpy_result);
	else
		cpy_result = flag_cs_tiret_case2(l_pattern, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}
