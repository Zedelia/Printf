/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_check.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:26:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 18:40:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	flag_check(char *flags)
{
	if (ft_isincharset('-', flags) && ft_isincharset('0', flags))
		return (False);
	if (ft_isdigit(flags[0]) && (ft_isincharset('-', flags) || ft_isincharset('0', flags)))
		return (False);


	return (True);
}
