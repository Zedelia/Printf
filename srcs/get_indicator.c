/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_indicator.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:17:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 11:46:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char 	get_indicator(char *pattern)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (pattern[i])
	{
		while (INDICATORS[j])
		{
			if (pattern[i] == INDICATORS[j])
				return (pattern[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (False);
}
