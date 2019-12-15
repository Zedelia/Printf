/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_indicator.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:04:10 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool 	get_indicator(t_pattern *l_pattern)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (l_pattern->pattern_cpy[i])
	{
		while (INDICATORS[j])
		{
			if (l_pattern->pattern_cpy[i] == INDICATORS[j])
			{
				l_pattern->indicator = l_pattern->pattern_cpy[i];
				return (True);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (false_ret(__func__));
}
