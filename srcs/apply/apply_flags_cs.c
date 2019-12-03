/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_cs.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 17:03:54 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 17:35:24 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
}
