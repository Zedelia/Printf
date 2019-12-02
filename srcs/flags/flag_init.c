/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 17:36:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:07:20 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	flag_init(t_flag **l_flag, char *flags, va_list params)
{

	if (!(*l_flag = malloc(sizeof(t_flag))))
		return (false_ret(__func__));
	(*l_flag)->precision = NULL;
	(*l_flag)->width = NULL;
	if (!(flag_parser(*l_flag, flags, params)))
		return (false_ret(__func__));
	return (True);
}