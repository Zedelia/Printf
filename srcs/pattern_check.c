/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pattern_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 18:26:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 12:41:38 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



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
	if (!(get_indicator(pattern)))
		return (false_ret(__func__));
	if (ft_isincharset('-', pattern) && ft_isincharset('0', pattern))
		return (false_ret(__func__));
	if ((ft_isdigit(pattern[0]) || pattern[0] == '*')
		&& (ft_isincharset('-', pattern) || ft_isincharset('0', pattern)))
		return (false_ret(__func__));
	// if (occurence('*', pattern) > 1 && )

	return (True);
}

t_bool	pattern_copy(t_pattern *l_pattern)
{
	size_t n;

	n = 1;
	while (is_indicator(l_pattern->p_pattern[n]) == False)
		n++;
	if (!(l_pattern->pattern_cpy = ft_strndup(&(l_pattern->p_pattern[1]), n + 1)))
		return (false_ret(__func__));
	if (!(pattern_check(l_pattern->pattern_cpy)))
		return (false_ret(__func__));
	return (True);
}
