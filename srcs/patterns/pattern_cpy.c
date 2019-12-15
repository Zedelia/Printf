/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_cpy.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:03:07 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:03:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	pattern_cpy(t_pattern *l_pattern)
{
	size_t n;

	n = 1;
	while (is_indicator(l_pattern->p_pattern[n]) == False)
		n++;
	if (!(l_pattern->pattern_cpy = ft_strndup(&(l_pattern->p_pattern[1]), n)))
		return (false_ret(__func__));
	if (!(pattern_check(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
