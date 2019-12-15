/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs_none.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:00:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_cs_none_case1(t_pattern *l_pattern, char *cpy_result)
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
		preci--;
	}
	return (cpy_result);
}


static char 	*flag_cs_none_case2(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int preci;
	int i;
	int j;

	i = 0;
	j = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	if (preci > 0)
	{
		while (width - preci > 0)
		{
			cpy_result[i++] = ' ';
			width--;
		}
		while (preci > 0)
		{
			cpy_result[i++] = l_pattern->result[j++];
			preci--;
		}
	}
	return (cpy_result);
}

static char 	*flag_cs_none_case3(t_pattern *l_pattern, char *cpy_result)
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
			cpy_result[i++] = ' ';
			width--;
		}
	}
	while (l_pattern->result[j])
		cpy_result[i++] = l_pattern->result[j++];
	return (cpy_result);
}

static char		*flag_cs_none_case4(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	while (width > 0)
	{
		cpy_result[i++] = ' ';
		width--;
	}
	return (cpy_result);
}


t_bool 		apply_cs_none(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	if (preci > width)
		cpy_result = flag_cs_none_case1(l_pattern, cpy_result);
	else if (preci)
		cpy_result = flag_cs_none_case2(l_pattern, cpy_result);
	else if (l_pattern->l_flag->preci && preci == 0)
		cpy_result = flag_cs_none_case4(l_pattern, cpy_result);
	else
		cpy_result = flag_cs_none_case3(l_pattern, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	return (True);
}
