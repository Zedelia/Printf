/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:34:03 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:12:50 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	pattern_init(t_pattern **self, char *format, va_list params)
{
	if (!(*self = malloc(sizeof(t_pattern))))
		return (False);
	if (!(*self)->pattern)
}
