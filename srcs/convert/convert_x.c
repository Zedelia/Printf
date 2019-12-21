/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_x.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:46 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_x(t_input *l_input)
{
	int cmp;
	int len;

	len = ft_strlen((char *)l_input->varg);
	cmp = ft_strncmp("0", (const char *)l_input->varg, len);
	if ((l_input->l_flag) && cmp == 0 && (l_input->l_flag->preci)
			&& *(int *)(l_input->l_flag->preci) == 0)
	{
		if (!(apply_diux_arg_zero(l_input)))
			return (False);
		return (True);
	}
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
		return (False);
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_diux(l_input)))
		return (False);
	return (True);
}
