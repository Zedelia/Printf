/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_copy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:49:26 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:08:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	pattern_copy(t_pattern *l_pattern)
{
	size_t n;

	n = 1;
	while (is_indicator(l_pattern->p_pattern[n]) == False)
		n++;
	if (!(l_pattern->pattern_cpy = ft_strndup(&(l_pattern->p_pattern[1]), n + 1)))
		return (false_ret(__func__));
	if (!(pattern_check(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
