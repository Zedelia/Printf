/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_percent.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 17:23:10 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:49:15 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool  convert_percent(t_pattern *l_pattern)
{
	if (!(l_pattern->result = malloc(sizeof(char) * 2)))
		return (false_ret(__func__));
	l_pattern->result[0] = l_pattern->indicateur;
	l_pattern->result[1] = '\0';
	if (!(l_pattern->l_flag))
		return (True);
	if (!(apply_percent(l_pattern)))
		return (false_ret(__func__));
	return (True);
}
