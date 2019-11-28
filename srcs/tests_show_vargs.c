/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_show_vargs.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 14:59:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 16:20:05 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	init_show_varg(void)
{
	g_show_varg[_c] = show_c;
	g_show_varg[_s] = show_s;
	g_show_varg[_p] = show_p;
	g_show_varg[_d] = show_di;
	g_show_varg[_i] = show_di;
	g_show_varg[_u] = show_u;
	g_show_varg[_x] = show_x;
	g_show_varg[_big_x] = show_x;
	g_show_varg[_percent] = show_percent;
}

void 	show_c(t_pattern *l_pattern)
{
	printf("%c\n", *((char *)l_pattern->varg));
}
void 	show_s(t_pattern *l_pattern)
{
	printf("%s\n", (char*)l_pattern->varg);
}
void 	show_p(t_pattern *l_pattern)
{
	printf("%p\n", l_pattern->varg);
}
void 	show_di(t_pattern *l_pattern)
{
	printf("%d\n", *((int *)l_pattern->varg));
}
void 	show_u(t_pattern *l_pattern)
{
	printf("%u\n", (unsigned int)l_pattern->varg);
}
void 	show_x(t_pattern *l_pattern)
{
	printf("%x\n", (unsigned int)l_pattern->varg);
}
void 	show_percent(t_pattern *l_pattern)
{
	printf("%c\n", (char)l_pattern->varg);
}

void 	show_varg(t_pattern *l_pattern)
{
	t_show_varg	*fonc;
	size_t 		index;

	init_show_varg();
	index = ft_index(l_pattern->indicateur, INDICATORS);
	fonc = g_show_varg[index];
	fonc(l_pattern);
}
