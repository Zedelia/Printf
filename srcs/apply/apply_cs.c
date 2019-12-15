/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_cs.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:00:43 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:00:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char 	*create_output_str_sc(t_input *l_input, char *cpy_output)
{
	int width;
	int preci;
	int len;
	int size ;

	len = ft_strlen(l_input->output);
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	preci = (l_input->l_flag->preci) ? *(int *)(l_input->l_flag->preci) : 0;
	if (width > len)
		size = width;
	else if (width > preci)
		size = width;
	else if (preci < len)
		size = preci;
	else
		size = len;
	if (!(cpy_output = malloc(sizeof(char)*(size + 1))))
		return (NULL);
	cpy_output[size] = '\0';
	return (cpy_output);
}

t_bool 	apply_cs(t_input *l_input)
{
	char *cpy_output;

	cpy_output = NULL;
	cpy_output = create_output_str_sc(l_input, cpy_output);
	if (l_input->l_flag->type == '-')
	{
		if (!(apply_cs_tiret(l_input, cpy_output)))
			return (false_ret(__func__));
	}
	else
	{
		if (!(apply_cs_none(l_input, cpy_output)))
			return (false_ret(__func__));
	}
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	ft_memdel((void**)&cpy_output);
	return (True);
}
