/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_parser.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 10:05:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 18:16:47 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool 	pattern_parser(t_pattern *l_pattern, va_list params)
{
	// t_flag *l_flags;

	if (ft_is_indicateur(l_pattern->pattern[1]) == True)
	{
		l_pattern->indicateur = l_pattern->pattern[1];
		l_pattern->l_flag = NULL;
// a supprimer cette ligne, on garde pour tests
		get_arg(l_pattern, params);
		// l_pattern->varg = (int)va_arg(params, int);
		l_pattern->len = 2;
		return (True);
	}
	// else if (ft_is_indicateur(l_pattern->pattern[1]) == False)
	// {
	// 	if (!(flags_init(&l_flags, &(l_pattern->pattern[1]), params)))
	// 		return (False);
	// 	l_pattern->l_flag = l_flags;
	// }
	return(True);
}
