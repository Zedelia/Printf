/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_apply_pattern.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 14:11:12 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 15:41:03 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	format_replace_pattern(t_format *s_format)
{

}
t_bool	format_apply_pattern(t_format *s_format)
{
	if (!(format_replace_pattern(s_format)))
		return (false_ret(__func__));
	return (False);
}
