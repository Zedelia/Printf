/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_cs.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 17:03:54 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 11:47:11 by mbos        ###    #+. /#+    ###.fr     */
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
	width = *(int *)(l_pattern->l_flag->width);
	preci = *(int *)(l_pattern->l_flag->precision);
	while (preci)
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

	i = 0;
	preci = 0;
	width = *(int *)(l_pattern->l_flag->width);
	if (l_pattern->l_flag->precision)
		preci = *(int *)(l_pattern->l_flag->precision);
	while (width - preci > 0)
	{
		copy_result[i++] = ' ';
		width--;
	}
	while (preci)
	{
		copy_result[i] = l_pattern->result[i];
		i++;
		preci--;
	}
	return (copy_result);
}


t_bool 		apply_flag_cs_none(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	preci = 0;
	width = *(int *)(l_pattern->l_flag->width);
	if (l_pattern->l_flag->precision)
		preci = *(int *)(l_pattern->l_flag->precision);
	if (preci > width)
		copy_result = flag_cs_none_case1(l_pattern, copy_result);
	else
		copy_result = flag_cs_none_case2(l_pattern, copy_result);

	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}

char 	*create_result_str_sc(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int preci;
	int len;
	int size ;

	preci = 0;
	len = ft_strlen(l_pattern->result);
	width = *(int *)(l_pattern->l_flag->width);
	if (l_pattern->l_flag->precision)
		preci = *(int *)(l_pattern->l_flag->precision);
	if (width > len)
		size = width;
	else if (width > preci)
		size = width;
	else if (preci < len)
		size = preci;
	else
		size = len;
	if (!(copy_result = malloc(sizeof(char)*(size + 1))))
		return (NULL);
	copy_result[size] = '\0';
	return (copy_result);
}

t_bool 	apply_flags_cs(t_pattern *l_pattern)
{
	char *copy_result;

	copy_result = NULL;
	copy_result = create_result_str_sc(l_pattern, copy_result);
	if (l_pattern->l_flag->flag_type == '-')
	{
		if (!(apply_flag_cs_tiret(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	// else
	// {
	// 	if (!(apply_flag_cs_none(l_pattern, copy_result)))
	// 		return (false_ret(__func__));
	// }
	ft_memdel((void**)&copy_result);
	return (True);
}
