/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs_none.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 13:27:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*flag_cs_none_case1(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	while (preci && l_input->output[i])
	{
		cpy_output[i] = l_input->output[i];
		i++;
		preci--;
	}
	return (cpy_output);
}


static char 	*flag_cs_none_case2(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int i;
	int j;
	int len ;

	i = 0;
	j = 0;
	len = ft_strlen(l_input->output);
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	preci = preci >= len ? len : preci;
	while (width - preci > 0)
	{
		cpy_output[i++] = ' ';
		width--;
	}
	while (preci > 0)
	{
		cpy_output[i++] = l_input->output[j++];
		preci--;
	}
	return (cpy_output);
}

static char		*flag_cs_none_case3(t_input *l_input, char *cpy_output)
{
	int width;
	int i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	while (width > 0)
	{
		cpy_output[i++] = ' ';
		width--;
	}
	return (cpy_output);
}

static char 	*flag_cs_none_case4(t_input *l_input, char *cpy_output)
{
	int width;
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(l_input->output);
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	if (width > len)
	{
		while (width - len > 0)
		{
			cpy_output[i++] = ' ';
			width--;
		}
	}
	while (l_input->output[j])
		cpy_output[i++] = l_input->output[j++];
	return (cpy_output);
}


t_bool 		apply_cs_none(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	if (preci > width)
		cpy_output = flag_cs_none_case1(l_input, cpy_output);
	else if (preci > 0)
		cpy_output = flag_cs_none_case2(l_input, cpy_output);
	else if (l_input->l_flag->preci && preci == 0)
		cpy_output = flag_cs_none_case3(l_input, cpy_output);
	else
		cpy_output = flag_cs_none_case4(l_input, cpy_output);
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	return (True);
}
