/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_flags_percent.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 17:19:42 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:03:36 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char  *create_result_str_percent(t_pattern *l_pattern)
{
	int  	width;
	char 	*copy_result;
	int		len;

	copy_result = NULL;
	width = (l_pattern->l_flag->width) ? *(int *)(l_pattern->l_flag->width) : 0;
	if (width > len)
		copy_result = create_malloc(copy_result, width);
	else
		copy_result = create_malloc(copy_result, len);
	else
		copy_result = create_malloc(copy_result, len);
	return (copy_result);
}


t_bool	apply_flags_percent(t_pattern *l_pattern)
{
	if (l_pattern->l_flag == '0' || l_pattern->l_flag == 'N')
	{

	}
	show_pattern(l_pattern);
	return (True);
}
