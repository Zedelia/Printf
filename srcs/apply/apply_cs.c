/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:43 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:00:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*create_result_str_sc(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int preci;
	int len;
	int size ;

	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	preci = (l_pattern->l_flag->preci) ? *(int *)(l_pattern->l_flag->preci) : 0;
	if (width > len)
		size = width;
	else if (width > preci)
		size = width;
	else if (preci < len)
		size = preci;
	else
		size = len;
	if (!(cpy_result = malloc(sizeof(char)*(size + 1))))
		return (NULL);
	cpy_result[size] = '\0';
	return (cpy_result);
}

t_bool 	apply_cs(t_pattern *l_pattern)
{
	char *cpy_result;

	cpy_result = NULL;
	cpy_result = create_result_str_sc(l_pattern, cpy_result);
	if (l_pattern->l_flag->type == '-')
	{
		if (!(apply_cs_tiret(l_pattern, cpy_result)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_cs_none(l_pattern, cpy_result)))
			return (false_ret(__func__));
	}
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	ft_memdel((void**)&cpy_result);
	return (True);
}
