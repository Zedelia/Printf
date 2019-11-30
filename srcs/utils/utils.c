/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 11:40:50 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 16:09:04 by mbos        ###    #+. /#+    ###.fr     */
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
	return (false_ret(__func__));
}

size_t	ft_index(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (c != charset[i])
		i++;
	return (i);
}

int		occurence_before(char c, char *charset, char before)
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

int		occurence_after(char c, char *charset, char after)
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
