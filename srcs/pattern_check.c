/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:26:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:23:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_indicator(char c)
{
	int i;

	i = 0;
	while (INDICATORS)
	{
		if (c == INDICATORS)
			return (True);
	}
	return (False);
}

t_bool	isolate_pattern(char *pattern)
{
	int i;

	i = 0;
	if (!(get_indicator(pattern)))
		return (False);
	while (is_indicator(pattern[i]) == False)
		i++;
}

int	occurence(char flag, char *charset)
{
	int i;
	int ocur;

	ocur = 0;
	i = 0;
	while (charset[i] != get_indicator(charset))
	{
		if (charset[i] == flag)
			ocur++;
		i++;
	}
	return (ocur);
}

t_bool	pattern_check(char *pattern)
{
	printf("%s\n", flags);
	if (ft_isincharset('-', flags) && ft_isincharset('0', flags))
		return (False);
	if ((ft_isdigit(flags[0]) || flags[0] == '*')
		&& (ft_isincharset('-', flags) || ft_isincharset('0', flags)))
		return (False);
	// if (occurence('*', flags) > 1 && )

	return (True);
}
