/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_width_preci.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 20:38:02 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:01:17 by melodiebos  ###    #+. /#+    ###.fr     */
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
