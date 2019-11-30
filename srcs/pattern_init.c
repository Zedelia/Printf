/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:34:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 12:35:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	pattern_init(t_pattern **l_pattern, char *format, va_list params)
{

	if (!(*l_pattern = malloc(sizeof(t_pattern))))
		return (false_ret(__func__));
	(*l_pattern)->next = NULL;
	(*l_pattern)->result = NULL;
	(*l_pattern)->p_pattern = format;
	(*l_pattern)->l_flag = NULL;
	(*l_pattern)->pattern_cpy = NULL;
	if (!(pattern_parser(*l_pattern, params)))
		return (false_ret(__func__));


	// (*l_pattern)->result = convert_me(*l_pattern);
	return (True);
}
