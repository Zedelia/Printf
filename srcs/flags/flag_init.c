/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:01:59 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 18:41:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	flag_init(t_flag **l_flag, char *flags, va_list params)
{
	if (!(*l_flag = malloc(sizeof(t_flag))))
		return (false_ret(__func__));
	(*l_flag)->preci = NULL;
	(*l_flag)->width = NULL;
	(*l_flag)->arg_weird = False;
	if (!(flag_parser(*l_flag, flags, params)))
		return (false_ret(__func__));
	return (True);
}
