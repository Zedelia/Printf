/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 19:59:36 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 10:43:55 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void 	*get_c(va_list params)
{
	char		*p_c;
	char 		var;

	var = va_arg(params, int);
	if (!(p_c = malloc(sizeof(char) * 2)))
		return (NULL);
	p_c[0] = var;
	p_c[1] = '\0';
	return ((void *)p_c);
}

void 	*get_s(va_list params)
{
	char		*p_s;
	char 		*var;

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

void 	*get_percent(va_list params)
{
	char		*p_percent;
	(void)params;

	if (!(p_percent = malloc(sizeof(char))))
		return (NULL);
	*p_percent = '%';
	return ((void *)p_percent);
}
