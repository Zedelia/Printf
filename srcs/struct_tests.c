/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_tests.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 13:16:30 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 14:02:28 by melodiebos  ###    #+. /#+    ###.fr     */
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

void 	show_pattern(t_pattern *l_pattern)
{
	t_pattern	 *temp;
	static int i = 1;

	temp = l_pattern->next;
	if (!l_pattern)
		printf("Pattern : (null)\n");
	else if (l_pattern)
	{
		if (l_pattern->pattern)
			printf(">>   [Pattern %d] : %s\n", i, l_pattern->pattern);
		if (l_pattern->result)
			printf("result : %s", l_pattern->result);
		if (l_pattern->varg)
			printf("varg : %d\n", l_pattern->varg);
		if (l_pattern->indicateur)
			printf("indicateur : %c\n", l_pattern->indicateur);
		if (l_pattern->l_flag)
			printf("l_flag : %p\n", l_pattern->l_flag);
		else if (!l_pattern->l_flag)
			printf("No flag\n");
		while (temp)
		{
			i++;
			printf("Next : %p\n-------------------\n", l_pattern->next);
			show_pattern(temp);
			temp = temp->next;
		}
		if (!l_pattern->next)
			printf("Next (null)\n-------------------\n");
	}
}
