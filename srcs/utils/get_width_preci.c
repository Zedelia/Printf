/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_width_preci.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 12:04:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int 	*get_width_preci(char *width_or_preci)
{
	size_t 	i;
	char 	*temp;
	int  	*p_int;

	i = 0;
	while (ft_isdigit(width_or_preci[i]) == True)
		i++;
	if (!(temp = ft_strndup((const char*)&width_or_preci[0], i)))
		return (NULL);
	if (!(p_int = malloc(sizeof(int))))
			return (NULL);
	*p_int = ft_atoi(temp);
	return ((void*)(p_int));
}
