/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_show_vargs.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 14:59:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:08:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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

void 	show_c(t_input *l_input)
{
	printf("arg_c : %c\n", *((char *)l_input->varg));
}
void 	show_s(t_input *l_input)
{
	printf("arg_s :%s\n", (char*)l_input->varg);
}
void 	show_p(t_input *l_input)
{
	printf("arg_p : %p\n", l_input->varg);
}
void 	show_di(t_input *l_input)
{
	printf("arg_di : %d\n", *((int *)l_input->varg));
}
void 	show_u(t_input *l_input)
{
	printf("arg_u : %u\n", (unsigned int)l_input->varg);
}
void 	show_x(t_input *l_input)
{
	printf("arg_xX : %x\n", (unsigned int)l_input->varg);
}
void 	show_percent(t_input *l_input)
{
	printf("arg_%% %c\n", (char)l_input->varg);
}

void 	show_varg(t_input *l_input)
{
	t_show_varg	*fonc;
	size_t 		index;

	init_show_varg();
	index = ft_index(l_input->indicator, INDICATORS);
	fonc = g_show_varg[index];
	fonc(l_input);
}
