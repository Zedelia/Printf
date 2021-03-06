/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:04:02 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:36:22 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	*get_c(va_list params)
{
	char	*p_c;
	char	var;

	var = va_arg(params, int);
	if (!(p_c = malloc(sizeof(char) * 2)))
		return (NULL);
	p_c[0] = var;
	p_c[1] = '\0';
	return ((void *)p_c);
}

void	*get_s(va_list params)
{
	char	*p_s;
	char	*var;

	var = va_arg(params, char*);
	if (!(var))
	{
		if (!(p_s = ft_strdup("(null)")))
			return (NULL);
		return ((void *)p_s);
	}
	if (!(p_s = ft_strdup(var)))
		return (NULL);
	return ((void *)p_s);
}

void	*get_percent(va_list params)
{
	char	*p_percent;

	if (!(p_percent = malloc(sizeof(char))))
		return (NULL);
	(void)params;
	*p_percent = '%';
	return ((void *)p_percent);
}
