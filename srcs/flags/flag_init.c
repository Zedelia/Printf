/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 17:36:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 14:10:56 by melodiebos  ###    #+. /#+    ###.fr     */
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
	(*l_flag)->arg_neg = False;
	if (!(flag_parser(*l_flag, flags, params)))
		return (false_ret(__func__));
	return (True);
}
