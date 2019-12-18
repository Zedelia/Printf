/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_arg_zero.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:41:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool	convert_zero(t_input *l_input)
{
	if (!(l_input->output = malloc(sizeof(char))))
		return (false_ret(__func__));
	l_input->output[0] = '\0';
	return (True);
}

t_bool			apply_diux_arg_zero(t_input *l_input)
{
	int i;

	if (*((int *)l_input->varg) == 48)
		*((int *)l_input->varg) = 0;
	l_input->output = ft_itoa(*((int *)l_input->varg));
	if (l_input->l_flag->arg_weird == True)
		return (True);
	if ((!(l_input->l_flag->width) || *(int *)(l_input->l_flag->width) == 0))
	{
		if (!(convert_zero(l_input)))
			return (false_ret(__func__));
	}
	else
	{
		i = 0;
		if (!(apply_diux(l_input)))
			return (false_ret(__func__));
		while (l_input->output[i])
			l_input->output[i++] = ' ';
	}
	return (True);
}
