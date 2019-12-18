/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_1.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:18 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:43:53 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t		ft_index(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (c != charset[i])
		i++;
	return (i);
}

char		*create_malloc(char *cpy_output, int len)
{
	if (!(cpy_output = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cpy_output[len] = '\0';
	return (cpy_output);
}
