/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:40:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 14:40:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	init_get_fct_tab(void)
{
	g_get_fct[_c] = get_c;
	g_get_fct[_s] = get_s;
	g_get_fct[_p] = get_p;
	g_get_fct[_d] = get_di;
	g_get_fct[_i] = get_di;
	g_get_fct[_u] = get_u;
	g_get_fct[_x] = get_x;
	g_get_fct[_big_x] = get_x;
	g_get_fct[_percent] = get_percent;
}

int		ft_is_indicateur(char c)
{
	char const *indicateurs;

	indicateurs = "%cspdiuxX";
	while (*indicateurs)
		if (c == *indicateurs++)
			return (True);
	return (False);
}

int		ft_is_flags(char c)
{
	char const *flags;

	flags = "-0.*";
	while (*flags)
		if (c == *flags++)
			return (True);
	return (False);
}

size_t	ft_index(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (c != charset[i])
		i++;
	return (i);
}
