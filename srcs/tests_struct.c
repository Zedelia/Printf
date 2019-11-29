/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_struct.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 13:16:30 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 11:45:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		if (s_format->l_pattern)
			show_pattern(s_format->l_pattern);
		else if (!s_format->l_pattern)
			printf("format->pattern : (null)\n-------------------\n" RESET);
	}
}

void 	show_one_pattern(t_pattern *l_pattern)
{
	if (!l_pattern)
		printf(YELLOW"Pattern : (null)\n"RESET);
	else if (l_pattern)
	{
		if (l_pattern->pattern)
			printf(YELLOW ">>   [Pattern] : %s\n", l_pattern->pattern);
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
			printf(YELLOW"Next (null)\n\n---------end----------"RESET"\n\n" RESET);
		else if (l_pattern->next)
			printf(YELLOW"Next %p\n" RESET, l_pattern->next);
	}
}

void 	show_pattern(t_pattern *l_pattern)
{
	t_pattern	 *temp;
	static int i = 0;

	temp = l_pattern;
	if (!l_pattern)
		printf(YELLOW "Pattern : (null)\n" RESET);
	while (temp)
	{
		i++;
		printf(YELLOW "\n-------------------\n\n Pattern %d\n" RESET, i);
		show_one_pattern(temp);
		temp = temp->next;
	}
}

void 	show_one_flag(t_flag *l_flag)
{
	if (!l_flag)
		printf (MAGENTA"Flag : (null)\n"RESET);
	else if (l_flag)
	{
		if (l_flag->flag_type)
			printf(MAGENTA"flag : %c\n", l_flag->flag_type);
		if (l_flag->precision)
			printf("precision : %d\n", l_flag->precision);
		if (l_flag->width)
			printf("width : %d\n", l_flag->width);
		if (!l_flag->next)
			printf(MAGENTA"Next (null)\n\n.....end.....<<"RESET"\n\n");
		else if (l_flag->next)
			printf("Next %p"RESET"\n", l_flag->next);
	}
}

void 	show_flag(t_flag *l_flag)
{
	t_flag	 *temp;
	static int i = 0;

	temp = l_flag;
	if (!l_flag)
		printf(MAGENTA"Flag : (null)\n");
	while (temp)
	{
		i++;
		printf(MAGENTA"\nflags.......>>\n\n  Flag %d\n" RESET, i);
		show_one_flag(temp);
		temp = temp->next;
	}
}
