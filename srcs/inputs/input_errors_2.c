/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_errors_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:14:26 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	error_digit_stars_together(t_input *l_input)
{
	int i;

	i = 0;
	if ((ft_isincharset('.', l_input->input_cpy)
		&& occur_after('*', l_input->input_cpy, '.') == 1))
	{
		while (l_input->input_cpy[i] != l_input->indicator)
		{
			if (ft_isdigit(l_input->input_cpy[i]))
				return (True);
			i++;
		}
	}
	if (occur_before('*', l_input->input_cpy, l_input->indicator) == 1
			&& (ft_isincharset('.', l_input->input_cpy)))
	{
		while (l_input->input_cpy[i] != l_input->indicator)
		{
			if (ft_isdigit(l_input->input_cpy[i]))
				return (True);
			i++;
		}
	}
	return (True);
}

t_bool	error_zeroflag_cp(t_input *l_input)
{
	if (l_input->input_cpy[0] == '0' &&
		(l_input->indicator == 'c' || l_input->indicator == 'p'))
		return (false_ret(__func__));
	return (True);
}
