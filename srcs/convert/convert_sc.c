/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_sc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_c(t_input *l_input)
{
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
		return (False);
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_cs(l_input)))
		return (False);
	return (True);
}

t_bool	convert_s(t_input *l_input)
{
	if (!(l_input->output = ft_strdup(((char *)l_input->varg))))
		return (False);
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_cs(l_input)))
		return (False);
	return (True);
}
