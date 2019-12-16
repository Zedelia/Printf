/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_sc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 15:28:49 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// static t_bool check_string(t_input *l_input)
// {
// 	if (!(l_input->output = ft_strdup("(null)")))
// 		return (false_ret(__func__));
// 	return (True);
// }

t_bool  convert_c(t_input *l_input)
{
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
			return (false_ret(__func__));
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_cs(l_input)))
		return (false_ret(__func__));
	return (True);
}

t_bool  convert_s(t_input *l_input)
{
	printf("varg %s\n", ((char *)l_input->varg) );
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
			return (false_ret(__func__));
	printf("output %s\n", ((char *)l_input->output) );
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_cs(l_input)))
		return (false_ret(__func__));
	return (True);
}
