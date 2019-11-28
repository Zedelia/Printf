/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_bases.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 11:56:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 12:04:46 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*convert_base_int_to_hex(unsigned int var);
{
	unsigned int		tmp;
	char				*hex;
	
	hex = "0123456789ABCDEF";
	if (test > 16)
		convert_base_int_to_hex(test / 16);
	tmp = test % 16;
	return (hex);
}
