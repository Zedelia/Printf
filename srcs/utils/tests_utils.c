/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 12:36:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 13:25:38 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_bool	false_ret(const char *namefunc)
{
	ft_printf(RED"%s"RESET"\n", namefunc);
	return (False);;
}
