/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_bases.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 11:56:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 00:01:12 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

// ne marche pas du tout a revoir

char	*convert_base_int_to_hex(unsigned int var)
{
	unsigned int		tmp;
	char				*hex;

	hex = "0123456789ABCDEF";
	if (var > 16)
		convert_base_int_to_hex(var / 16);
	tmp = var % 16;
	return (hex);
}
