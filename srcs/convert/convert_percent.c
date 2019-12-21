/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_percent.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_percent(t_input *l_input)
{
	if (!(l_input->output = malloc(sizeof(char) * 2)))
		return (False);
	l_input->output[0] = l_input->indicator;
	l_input->output[1] = '\0';
	if (!(l_input->l_flag))
		return (True);
	if (!(apply_percent(l_input)))
		return (False);
	return (True);
}
