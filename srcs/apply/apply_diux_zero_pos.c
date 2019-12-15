/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_diux_zero_pos.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:13:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*f_zero_di_case1(t_input *l_input, int preci, char *cpy_output)
{
	int len;
	int i;

	len = ft_strlen(l_input->output) - 1;
	i = len > preci ? len : preci - 1;
	while (len  >= 0)
	{
		cpy_output[i] = (l_input->output)[len];
		preci--;
		len--;
		i--;
	}
	while (preci >= 0)
	{
		cpy_output[i--] = '0';
		preci--;
	}
	return (cpy_output);
}

static char 	*f_zero_di_case2(t_input *l_input, int width, char *cpy_output)
{
	int len;

	len = ft_strlen(l_input->output);
	width = (width > len) ? width : len;
	while (len >= 0)
		cpy_output[width--] = (l_input->output)[len--];
	if (l_input->l_flag->type == 'N')
	{
		while (width >= 0)
			cpy_output[width--] = ' ';
	}
	else if (l_input->l_flag->type == '0')
	{
		while (width >= 0)
			cpy_output[width--] = '0';
	}
	return (cpy_output);
}

static char 	*f_zero_di_case3(t_input *l_input, int preci, int width, char *cpy_output)
{
	int len;
	int i;

	len = ft_strlen(l_input->output) - 1;
	width--;
	preci--;
	i = width < len ? len : width;
	while (len >= 0)
	{
		cpy_output[i--] = (l_input->output)[len--];
		preci--;
		width--;
	}
	while (preci >= 0)
	{
		cpy_output[i--] = '0';
		preci--;
		width--;
	}
	while (width >= 0)
		cpy_output[width--] = ' ';
	return (cpy_output);
}

t_bool		apply_diux_zero_pos(t_input *l_input, char *cpy_output)
{
	int width;
    int preci;

	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	if ((l_input->l_flag->preci) && preci > width)
		cpy_output = f_zero_di_case1(l_input, preci, cpy_output);
	else if (!(l_input->l_flag->preci))
		cpy_output = f_zero_di_case2(l_input, width, cpy_output);
	else if (preci <= width)
		cpy_output = f_zero_di_case3(l_input, preci, width, cpy_output);
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	return (True);
}
