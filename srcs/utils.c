/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:40:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 12:33:27 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_indicateur(char c)
{
	char const *indicateurs;

	indicateurs = "%cspdiuxX";
	while (*indicateurs)
		if (c == *indicateurs++)
			return (True);
	return (False);
}

int		ft_is_flags(char c)
{
	char const *flags;

	flags = "-0.*";
	while (*flags)
		if (c == *flags++)
			return (True);
	return (False);
}
