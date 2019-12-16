/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_arg_zero.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 13:53:17 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool 	convert_zero(t_input *l_input)
{
	if (!(l_input->output = malloc(sizeof(char))))
		return (false_ret(__func__));
	l_input->output[0] = '\0';
	return (True);
}

t_bool	apply_diux_arg_zero(t_input *l_input)
{
	int i;

	i = 0;
	l_input->output = ft_itoa(*((int *)l_input->varg));
	if (l_input->l_flag->arg_neg == True)
		return (True);
	if ((!(l_input->l_flag->width) || *(int *)(l_input->l_flag->width) == 0))
	{
		if (!(convert_zero(l_input)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_diux(l_input)))
			return (false_ret(__func__));
		while(l_input->output[i])
			l_input->output[i++] = ' ';
	}
	return (True);
}
