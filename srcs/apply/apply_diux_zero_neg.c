/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_zero_neg.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:01 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:41:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char		*f_z_di_case1(t_input *l_input, int preci, char *cpy_output)
{
	int len;
	int i;

	len = ft_strlen(l_input->output);
	len--;
	i = preci > len ? preci : len;
	cpy_output[0] = '-';
	while (len > 0)
	{
		cpy_output[i--] = (l_input->output)[len--];
		preci--;
	}
	while (preci > 0)
	{
		cpy_output[i--] = '0';
		preci--;
	}
	return (cpy_output);
}

static char		*f_z_di_case2(t_input *l_input, int width, char *cpy_output)
{
	int len;

	len = ft_strlen(l_input->output);
	if (width < len)
		width = len;
	while (len > 0)
		cpy_output[width--] = (l_input->output)[len--];
	if (l_input->l_flag->type == 'N')
	{
		cpy_output[width--] = '-';
		while (width >= 0)
			cpy_output[width--] = ' ';
	}
	else if (l_input->l_flag->type == '0')
	{
		while (width > 0)
			cpy_output[width--] = '0';
		cpy_output[width--] = '-';
	}
	return (cpy_output);
}

static char		*f_z_di_case3(
	t_input *l_input,
	int preci,
	int width,
	char *cpy_output)
{
	int len;
	int i;

	len = ft_strlen(l_input->output);
	i = (width > len) ? width : len;
	while (len > 0)
	{
		cpy_output[i--] = (l_input->output)[len--];
		preci--;
	}
	while (preci >= 0)
	{
		cpy_output[i--] = '0';
		preci--;
	}
	cpy_output[i--] = '-';
	while (i >= 0)
		cpy_output[i--] = ' ';
	return (cpy_output);
}

t_bool			apply_diux_zero_neg(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;

	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	preci = (l_input->l_flag->arg_weird) ? preci - 1 : preci;
	if ((l_input->l_flag->preci) && preci >= width)
		cpy_output = f_z_di_case1(l_input, preci, cpy_output);
	else if (!(l_input->l_flag->preci))
		cpy_output = f_z_di_case2(l_input, width, cpy_output);
	else if ((l_input->l_flag->preci) && preci < width)
		cpy_output = f_z_di_case3(l_input, preci, width, cpy_output);
	if (l_input->output)
		ft_memdel((void**)&l_input->output);
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	return (True);
}
