/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:03:18 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 17:14:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_width(t_flag *l_flag, char *flags, va_list params)
{
	size_t i;
	(void)params;

	i = 0;
	while (ft_isalnum(flags[i]) == True)
		i++;
	l_flag->width = ft_atoi(ft_strndup((const char*)&flags[i], i));

	return (0);
}

t_bool		flag_parser(t_flag *l_flag, char *flags, va_list params)
{
	if (flags[0] == '0' ||flags[0] == '-')
	{
		l_flag->flag_type = flags[0];
		l_flag->width = flag_width(l_flag, &flags[1], params);
	}


	return (True);
	// while (ft_isalnum(l_flags->flag[i]) == True)
	// {
	// 	// faire une methode pour ca
	// 	l_flag->width = flag_num();
	// }
}
