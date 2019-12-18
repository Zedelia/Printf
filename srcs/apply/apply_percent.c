/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply_percent.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:22 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 11:49:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*create_output_str_percent(t_input *l_input)
{
	int		width;
	char	*cpy_output;

	cpy_output = NULL;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	if (width > 1)
		cpy_output = create_malloc(cpy_output, width);
	else
		cpy_output = create_malloc(cpy_output, 1);
	return (cpy_output);
}

static char	*apply_percent_none(t_input *l_input, char *cpy_output)
{
	int		width;
	int		i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	while (i < width - 1)
		cpy_output[i++] = ' ';
	cpy_output[i] = '%';
	return (cpy_output);
}

static char	*apply_percent_tiret(t_input *l_input, char *cpy_output)
{
	int		width;
	int		i;

	i = 1;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	cpy_output[0] = '%';
	while (i < width)
		cpy_output[i++] = ' ';
	return (cpy_output);
}

static char	*apply_percent_zero(t_input *l_input, char *cpy_output)
{
	int		width;
	int		i;

	i = 0;
	width = (l_input->l_flag->width) ? *(int *)(l_input->l_flag->width) : 0;
	while (i < width - 1)
		cpy_output[i++] = '0';
	cpy_output[i] = '%';
	return (cpy_output);
}

t_bool		apply_percent(t_input *l_input)
{
	char	*cpy_output;

	if (!(cpy_output = create_output_str_percent(l_input)))
		return (false_ret(__func__));
	if (l_input->l_flag->type == 'N')
		cpy_output = apply_percent_none(l_input, cpy_output);
	else if (l_input->l_flag->type == '-')
		cpy_output = apply_percent_tiret(l_input, cpy_output);
	else if (l_input->l_flag->type == '0')
		cpy_output = apply_percent_zero(l_input, cpy_output);
	if (l_input->output)
		ft_memdel((void**)&l_input->output);
	if (!(l_input->output = ft_strdup(cpy_output)))
		return (false_ret(__func__));
	ft_memdel((void**)&cpy_output);
	return (True);
}
