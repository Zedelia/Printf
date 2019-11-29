/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_struct.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 13:16:30 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 18:17:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	show_format(t_format *s_format)
{
	if (!s_format)
		printf("Format : (null)");
	else if (s_format)
	{
	 	printf("Format adress: %p\n", s_format);
		if (s_format->format)
			printf("format content : %s\n",s_format->format);
		else if (!s_format->format)
			printf("Format : empty\n");
		if (s_format->l_pattern)
			printf("Format pattern list : %p\n-------------------\n", s_format->l_pattern);
		else if (!s_format->l_pattern)
			printf("format->pattern : (null)\n-------------------\n");
	}
}

void 	show_one_pattern(t_pattern *l_pattern)
{
	if (!l_pattern)
		printf("Pattern : (null)\n");
	else if (l_pattern)
	{
		if (l_pattern->pattern)
			printf(">>   [Pattern] : %s\n", l_pattern->pattern);
		if (l_pattern->result)
			printf("result : %s", l_pattern->result);
		if (l_pattern->varg)
			show_varg(l_pattern);
		if (l_pattern->indicateur)
			printf("indicateur : %c\n", l_pattern->indicateur);
		if (l_pattern->l_flag)
			printf("l_flag : %p\n", l_pattern->l_flag);
		else if (!l_pattern->l_flag)
			printf("No flag\n");
		show_flag(l_pattern->l_flag);
		if (!l_pattern->next)
			printf("Next (null)\n\n---------end----------\n\n");
		else if (l_pattern->next)
			printf("Next %p\n", l_pattern->next);
	}
}

void 	show_pattern(t_pattern *l_pattern)
{
	t_pattern	 *temp;
	static int i = 0;

	temp = l_pattern;
	if (!l_pattern)
		printf("Pattern : (null)\n");
	while (temp)
	{
		i++;
		printf("\n-------------------\n\n Pattern %d\n", i);
		show_one_pattern(temp);
		temp = temp->next;
	}
}

void 	show_one_flag(t_flag *l_flag)
{
	if (!l_flag)
		printf ("Flag : (null)\n");
	else if (l_flag)
	{
		if (l_flag->flag_type)
			printf("flag : %c\n", l_flag->flag_type);
		if (l_flag->precision)
			printf("precision : %d\n", l_flag->precision);
		if (l_flag->width)
			printf("width : %d\n", l_flag->width);
		if (!l_flag->next)
			printf("Next (null)\n\n.........end.........\n\n");
		else if (l_flag->next)
			printf("Next %p\n", l_flag->next);
	}
}

void 	show_flag(t_flag *l_flag)
{
	t_flag	 *temp;
	static int i = 0;

	temp = l_flag;
	if (!l_flag)
		printf("Flag : (null)\n");
	while (temp)
	{
		i++;
		printf("\nflags.......>>\n\nFlag %d\n", i);
		show_one_flag(temp);
		temp = temp->next;
	}
}
