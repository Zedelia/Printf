/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_preci.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:04:13 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:36:30 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		*get_width_preci(char *width_or_preci)
{
	size_t		i;
	char		*temp;
	int			*p_int;
	int			start;

	start = 0;
	while (width_or_preci[start] == '-')
		start++;
	i = start;
	while (ft_isdigit(width_or_preci[i]) == True)
		i++;
	if (!(temp = ft_strndup((const char*)&width_or_preci[start], i - start)))
		return (NULL);
	if (!(p_int = malloc(sizeof(int))))
		return (NULL);
	*p_int = ft_atoi(temp);
	ft_memdel((void**)&temp);
	*p_int = (*p_int < 0) ? -*p_int : *p_int;
	return ((void*)(p_int));
}
