/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_di_tiret.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:55:59 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 12:41:30 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool apply_flag_di_tiret(char *copy_result, t_pattern *l_pattern)
{
	int len ;
	int width;
    int precision;
	int i;
    int j;

	i = 0;
    j = 0;
	len = ft_strlen(l_pattern->result);
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
    precision = (l_pattern->l_flag->precision) ? *(int *)(l_pattern->l_flag->precision) : 0;
	while (i < precision - len)
		copy_result[i++] = '0';
	while ((l_pattern->result)[j])
		copy_result[i++] = (l_pattern->result)[j++];
    while (width - i > 0 && copy_result[i])
        copy_result[i++] = ' ';
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	return (True);
}
