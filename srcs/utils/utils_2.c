/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 12:04:21 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 12:17:25 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	is_indicator(char c)
{
	int i;

	i = 0;
	while (INDICATORS[i])
	{
		if (c == INDICATORS[i])
			return (True);
		i++;
	}
	return (False);
}

int		is_flags(char c)
{
	char const *flags;

	flags = "-0.*";
	while (*flags)
		if (c == *flags++)
			return (True);
	return (False);
}

int		occur_before(char c, char *charset, char before)
{
	int i;
	int ocur;

	ocur = 0;
	i = 0;
	while (charset[i] && charset[i] != before)
	{
		if (charset[i] == c)
			ocur++;
		i++;
	}
	return (ocur);
}

int		occur_after(char c, char *charset, char after)
{
	int i;
	int ocur;

	ocur = 0;
	i = 0;
	while (charset[i] && charset[i] != after)
		i++;
	while (charset[i])
	{
		if (charset[i] == c)
			ocur++;
		i++;
	}
	return (ocur);
}
