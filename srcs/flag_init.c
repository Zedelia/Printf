/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 17:36:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 17:11:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	flag_init(t_flag **l_flag, char *flag, va_list params)
{
	(void)params;
	if (!(*l_flag = malloc(sizeof(t_flag))))
		return (False);
	(*l_flag)->flag_type = flag[0];
	(*l_flag)->next = NULL;
	// flag_parser(*l_flag, params);
	return (True);
}
