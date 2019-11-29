/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 17:36:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:59:33 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	flag_init(t_flag **l_flag, char *flags, va_list params)
{

	if (!(*l_flag = malloc(sizeof(t_flag))))
		return (False);
	(*l_flag)->precision = NULL;
	(*l_flag)->width = NULL;
	if (!(flag_parser(*l_flag, flags, params)))
		return (False);
	return (True);
}
