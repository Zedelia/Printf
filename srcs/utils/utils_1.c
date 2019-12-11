/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_1.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:40:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 14:50:47 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_index(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (c != charset[i])
		i++;
	return (i);
}

char 	*create_malloc(char *copy_result, int len)
{
	if (!(copy_result = malloc(sizeof(char)*(len + 1))))
		return (NULL);
	copy_result[len] = '\0';
	return (copy_result);
}
