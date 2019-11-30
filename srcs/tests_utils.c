/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 12:36:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/30 12:38:10 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// false_ret(__func__)
t_bool false_ret(const char *namefunc)
{
	printf(RED"%s"RESET"\n", namefunc);
	return (False);
}
