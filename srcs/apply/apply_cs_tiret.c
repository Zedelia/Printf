/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs_tiret.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:35 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:43:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char		*flag_cs_tiret_case1(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	if (preci > 0)
	{
		while (preci && l_input->output[i])
		{
			cpy_output[i] = l_input->output[i];
			i++;
			width--;
			preci--;
		}
	}
	while (width > 0)
	{
		cpy_output[i] = ' ';
		i++;
		width--;
	}
	return (cpy_output);
}

static char		*flag_cs_tiret_case2(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	while (l_input->output[i])
	{
		cpy_output[i] = l_input->output[i];
		i++;
		width--;
	}
	while (width > 0)
	{
		cpy_output[i] = ' ';
		i++;
		width--;
	}
	return (cpy_output);
}

t_bool			apply_cs_tiret(t_input *l_input)
{
	char *cpy_output;

	cpy_output = NULL;
	cpy_output = create_output_str_sc(l_input, cpy_output);
	if (l_input->l_flag->preci && *(int *)(l_input->l_flag->preci) >= 0)
		cpy_output = flag_cs_tiret_case1(l_input, cpy_output);
	else
		cpy_output = flag_cs_tiret_case2(l_input, cpy_output);
	if (l_input->output)
		ft_memdel((void**)&l_input->output);
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));;
	ft_memdel((void**)&cpy_output);
	return (True);
}
