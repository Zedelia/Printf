/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_struct.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:03:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:08:54 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	show_format(t_format *s_format)
{
	if (!s_format)
		printf(CYAN "Format : (null)" RESET);
	else if (s_format)
	{
	 	printf(CYAN "   Format\nFormat adress: %p\n", s_format);
		if (s_format->format)
			printf("format content : %s" ,s_format->format);
		else if (!s_format->format)
			printf("Format : empty" );
		if (s_format->l_input)
			show_input(s_format->l_input);
		else if (!s_format->l_input)
			printf("format->input : (null)\n-------------------\n" RESET);
	}
}

void 	show_one_input(t_input *l_input)
{
	if (!l_input)
		printf(YELLOW"input : (null)\n"RESET);
	else if (l_input)
	{
		if (l_input->p_input)
			printf(YELLOW ">>   [p_input] : %s\n", l_input->p_input);
		if (l_input->input_cpy)
			printf(YELLOW "input : %s\n", l_input->input_cpy);
		if (l_input->output)
			printf("output : [%s]\n", l_input->output);
		if (l_input->varg)
			show_varg(l_input);
		if (l_input->len)
			printf("input_len : [%d]\n", l_input->len);
		if (l_input->indicator)
			printf("indicator : %c\n", l_input->indicator);
		if (l_input->l_flag)
			printf("l_flag : %p\n", l_input->l_flag);
		show_flag(l_input->l_flag);
		if (!l_input->next)
			printf(YELLOW"Next (null)\n\n---------end----------"RESET"\n\n" RESET);
		else if (l_input->next)
			printf(YELLOW"Next %p\n" RESET, l_input->next);
	}
}

void 	show_input(t_input *l_input)
{
	t_input	 *temp;
	static int i = 0;

	temp = l_input;
	if (!l_input)
		printf(YELLOW "input : (null)\n" RESET);
	while (temp)
	{
		i++;
		printf(YELLOW "\n-------------------\n\n input %d\n" RESET, i);
		show_one_input(temp);
		temp = temp->next;
	}
}

void 	show_one_flag(t_flag *l_flag)
{
	if (!l_flag)
		printf (MAGENTA"Flag : (null)\n"RESET);
	else if (l_flag)
	{
		if (l_flag->type)
			printf(MAGENTA"flag : %c\n", l_flag->type);
		if (l_flag->preci)
			printf("preci : %d\n", *((int *)l_flag->preci));
		if (l_flag->width)
			printf("width : %d\n", *((int *)l_flag->width));
		printf(MAGENTA"\n.....end.....<<"RESET"\n\n");
	}
}


void 	show_flag(t_flag *l_flag)
{
	t_flag	 *temp;

	temp = l_flag;
	if (!l_flag)
	{
		printf(MAGENTA"Flag : (null)\n");
		return ;
	}
	printf(MAGENTA"\nflag.......>>\n \n" RESET);
	show_one_flag(temp);

}
