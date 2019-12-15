/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_percent.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 17:19:42 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 10:59:55 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char  *create_result_str_percent(t_pattern *l_pattern)
{
	int  	width;
	char 	*copy_result;

	copy_result = NULL;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (width > 1)
		copy_result = create_malloc(copy_result, width);
	else
		copy_result = create_malloc(copy_result, 1);
	return (copy_result);
}

static char	*apply_percent_none(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	while (i < width - 1)
		copy_result[i++] = ' ';
	copy_result[i] = '%';
	return (copy_result);
}

static char	*apply_percent_tiret(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int i ;

	i = 1;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	copy_result[0] = '%';
	while (i < width)
		copy_result[i++] = ' ';
	return (copy_result);
}

static char	*apply_percent_zero(t_pattern *l_pattern, char *copy_result)
{
	int width;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	while (i < width - 1)
		copy_result[i++] = '0';
	copy_result[i] = '%';
	return (copy_result);
}

t_bool	apply_percent(t_pattern *l_pattern)
{
	char *copy_result;

	if (!(copy_result = create_result_str_percent(l_pattern)))
		return (false_ret(__func__));
	if (l_pattern->l_flag->flag_type == 'N')
		copy_result = apply_percent_none(l_pattern, copy_result);
	else if (l_pattern->l_flag->flag_type == '-')
		copy_result = apply_percent_tiret(l_pattern, copy_result);
	else if (l_pattern->l_flag->flag_type == '0')
		copy_result = apply_percent_zero(l_pattern, copy_result);
	if (!(l_pattern->result = ft_strdup(copy_result)))
		return (false_ret(__func__));
	ft_memdel((void**)&copy_result);
	return (True);
}
