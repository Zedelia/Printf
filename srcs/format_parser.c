/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_parser.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 18:55:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 19:22:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void format_add_pattern(t_format *s_format, t_pattern *l_pattern)
{
	t_pattern *temp;

	temp = s_format->l_pattern;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = l_pattern;
}





t_bool	format_parser(t_format *s_format, char *format, va_list params)
{
	t_pattern *l_pattern;
	char 	*cp_format;

	cp_format = format;
	// if ((cp_format = ft_strchr(cp_format, "%")
	// {
	// 	if (!(pattern_init(&l_pattern, cp_format, params)))
	// 		return (False);
	// 	s_format->l_pattern = l_pattern;

// methode pour ce morceau
		while (cp_format && (cp_format = ft_strchr(cp_format + 1, "%")))
		{
			if (!(pattern_init(&l_pattern, cp_format, params)))
					return (False);
			format_add_pattern(s_format, l_pattern);
		}

	// }
	return (True);
}