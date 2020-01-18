/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_indicator.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:13:59 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 16:43:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	input_indicator(t_input *l_input)
{
	if (!(get_indicator(l_input)))
		return (false_ret(__func__));;
	return (True);
}
