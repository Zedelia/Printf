/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:34:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 13:46:02 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	pattern_init(t_pattern **l_pattern, char *format, va_list params)
{
	// t_flag *l_flags;

	if (!(*l_pattern = malloc(sizeof(t_pattern))))
		return (False);
	(*l_pattern)->next = NULL;
	(*l_pattern)->result = NULL;
	(*l_pattern)->pattern = format;
	if (ft_is_indicateur(format[1]) == True)
	{
		(*l_pattern)->indicateur = format[1];
		(*l_pattern)->l_flag = NULL;
	// a supprimer cette ligne, on garde pour tests
		(*l_pattern)->varg = (int)va_arg(params, int);
		(*l_pattern)->len = 2;
	}
	// else if (ft_is_indicateur(format[1]) == False)
	// {
	// 	if (!(flags_init(&l_flags, &format[1], params)))
	// 		return (False);
	// 	(*l_pattern)->l_flag = l_flags;
	// }
	// (*l_pattern)->result = convert_me(*l_pattern);
	return (True);
}
