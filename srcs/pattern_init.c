/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:34:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 17:08:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	pattern_init(t_pattern **l_pattern, char *format, va_list params)
{

	if (!(*l_pattern = malloc(sizeof(t_pattern))))
		return (False);
	(*l_pattern)->next = NULL;
	(*l_pattern)->result = NULL;
	(*l_pattern)->pattern = format;
	(*l_pattern)->l_flag = NULL;
	pattern_parser(*l_pattern, params);


	// (*l_pattern)->result = convert_me(*l_pattern);
	return (True);
}
