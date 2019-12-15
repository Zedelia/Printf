/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_percent.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:01:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char  *create_result_str_percent(t_pattern *l_pattern)
{
	int  	width;
	char 	*cpy_result;

	cpy_result = NULL;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (width > 1)
		cpy_result = create_malloc(cpy_result, width);
	else
		cpy_result = create_malloc(cpy_result, 1);
	return (cpy_result);
}

static char	*apply_percent_none(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	while (i < width - 1)
		cpy_result[i++] = ' ';
	cpy_result[i] = '%';
	return (cpy_result);
}

static char	*apply_percent_tiret(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int i ;

	i = 1;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	cpy_result[0] = '%';
	while (i < width)
		cpy_result[i++] = ' ';
	return (cpy_result);
}

static char	*apply_percent_zero(t_pattern *l_pattern, char *cpy_result)
{
	int width;
	int i;

	i = 0;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	while (i < width - 1)
		cpy_result[i++] = '0';
	cpy_result[i] = '%';
	return (cpy_result);
}

t_bool	apply_percent(t_pattern *l_pattern)
{
	char *cpy_result;

	if (!(cpy_result = create_result_str_percent(l_pattern)))
		return (false_ret(__func__));
	if (l_pattern->l_flag->type == 'N')
		cpy_result = apply_percent_none(l_pattern, cpy_result);
	else if (l_pattern->l_flag->type == '-')
		cpy_result = apply_percent_tiret(l_pattern, cpy_result);
	else if (l_pattern->l_flag->type == '0')
		cpy_result = apply_percent_zero(l_pattern, cpy_result);
	if (!(l_pattern->result = ft_strdup(cpy_result)))
		return (false_ret(__func__));
	ft_memdel((void**)&cpy_result);
	return (True);
}
