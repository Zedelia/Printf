/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_cpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_cpy(t_input *l_input)
{
	size_t n;

	n = 1;
	while (is_indicator(l_input->p_input[n]) == False)
		n++;
	if (!(l_input->input_cpy = ft_strndup(&(l_input->p_input[1]), n)))
		return (False);
	if (!(input_indicator(l_input)))
		return (False);
	return (True);
}
