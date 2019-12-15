/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_tiret.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:00:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_bool 	apply_diux_tiret_neg(char *cpy_output, t_input *l_input)
{
	int len ;
	int width;
	int preci;
	int i;
	int j;

	i = 0;
    j = 0;
	len = ft_strlen(l_input->output);
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	cpy_output[i++] = '-';
	j++;
	len--;
	while (i <= preci - len)
		cpy_output[i++] = '0';
	while ((l_input->output)[j])
		cpy_output[i++] = (l_input->output)[j++];
    while (width - i > 0)
        cpy_output[i++] = ' ';
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	return (True);
}


static t_bool 	apply_diux_tiret_pos(char *cpy_output, t_input *l_input)
{
	int len ;
	int width;
	int preci;
	int i;
	int j;

	i = 0;
	j = 0;
	len = ft_strlen(l_input->output);
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	while (i < preci - len)
		cpy_output[i++] = '0';
	while ((l_input->output)[j])
		cpy_output[i++] = (l_input->output)[j++];
	while (width - i > 0)
		cpy_output[i++] = ' ';
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	return (True);
}

t_bool apply_diux_tiret(char *cpy_output, t_input *l_input)
{
	if (ft_atoi(l_input->output) < 0 && l_input->indicator != 'u')
	{
		if (!(apply_diux_tiret_neg(cpy_output, l_input)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_diux_tiret_pos(cpy_output, l_input)))
			return (false_ret(__func__));
	}
	return (True);
}
