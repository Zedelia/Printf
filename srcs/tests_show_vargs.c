/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_show_vargs.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 14:59:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 15:43:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void

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

void 	g_show_varg(char c)
{
	printf("")
}

void 	show_varg(t_pattern *l_pattern)
{
	t_get_fct 	*fonc;
	size_t 		index;

	init_show_varg();
	index = ft_index(l_pattern->indicateur, INDICATORS);
	fonc = g_show_varg[index];
	l_pattern->varg = fonc(l_pattern->indicateur);
}
