/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 12:36:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 15:42:36 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	false_ret(const char *namefunc)
{
	printf(RED"%s"RESET"\n", namefunc);
	return (False);
}
