/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_cs.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 17:03:54 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 18:27:23 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char 	*flag_cs_tiret_case1(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = *(int *)(l_pattern->l_flag->width);
	precision = *(int*)(l_pattern->l_flag->precision);
	while (precision && l_pattern->result[i])
	{
		copy_result[i] = l_pattern->result[i++];
		width--;
		precision--;
	}
	while (width)
	{
		copy_result[i] = ' ';
		width--;
	}
	return (copy_result);
}

char 	*flag_cs_tiret_case2(l_pattern, copy_result)

t_bool 		apply_flag_cs_tiret(t_pattern *l_pattern, char *copy_result)
{
	int len ;

    if (l_pattern->l_flag->precision)
		copy_result = flag_cs_tiret_case1(l_pattern, copy_result);
	else
		copy_result = flag_cs_tiret_case2(l_pattern, copy_result)
	{
		while (l_pattern->result[i])
		{
			copy_result[i] = l_pattern->result[i++];
			width--;
		}
	}
	while (width)
		copy_result[i] = ' ';
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
}

t_bool 		apply_flag_cs_none(t_pattern *l_pattern, char *copy_result)
{

}

static char 	*create_result_str_sc(t_pattern *l_pattern)
{
	int with;
	int preci;
	int len;
	int size ;

	precision = 0;
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

	copy_result = create_result_str_sc(l_pattern);
	if (l_pattern->l_flag->flag_type = '-')
	{
		if (!(apply_flag_cs_tiret(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_flag_cs_none(l_pattern, copy_result)))
			return (false_ret(__func__));
	}
	t_memdel((void**)&copy_result);
	return (True);
}
