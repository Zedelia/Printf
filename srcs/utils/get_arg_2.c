/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 19:59:36 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 19:59:47 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

//-------------------------------------------------- A FAIRE
void 	*get_u(va_list params)
{
	unsigned int	*p_int;
	unsigned int 	var;

	var = va_arg(params, unsigned int);
    if (!(p_int = malloc(sizeof(unsigned int))))
		return (NULL);
    *p_int = var;
	return ((void *)p_int);
}

//--------------------------------------------------
