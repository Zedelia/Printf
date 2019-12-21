/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_parser.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:14:44 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool		input_parser(t_input *l_input, va_list params)
{
	t_flag *l_flag;

	if (!(input_cpy(l_input)))
		return (False);
	l_input->len = ft_strlen(l_input->input_cpy) + 1;
	if (is_indicator(l_input->input_cpy[0]) == True)
	{
		if (!(get_arg(l_input, params)))
			return (False);
	}
	if (is_indicator(l_input->input_cpy[0]) == False)
	{
		if (!(flag_init(&l_flag, l_input->input_cpy, params)))
			return (False);
		l_input->l_flag = l_flag;
		if (!(get_arg(l_input, params)))
			return (False);
	}
	return (True);
}
