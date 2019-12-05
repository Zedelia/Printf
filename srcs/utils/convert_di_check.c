/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_di_check.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 11:22:51 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 14:47:40 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	convert_di_check(t_pattern *l_pattern)
{
	if (!(l_pattern->result = ft_strdup(((char*)(l_pattern->varg)))))
		return (false_ret(__func__));
	l_pattern->result[0] = '\0';
	return (True);
}
