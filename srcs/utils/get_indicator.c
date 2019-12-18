/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_indicator.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:51:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	get_indicator(t_input *l_input)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (l_input->input_cpy[i])
	{
		while (INDICATORS[j])
		{
			if (l_input->input_cpy[i] == INDICATORS[j])
			{
				l_input->indicator = l_input->input_cpy[i];
				return (True);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (false_ret(__func__));
}
