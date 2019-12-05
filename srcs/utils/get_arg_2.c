/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arg_2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 15:58:34 by mbos         #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2019/12/04 22:47:39 by melodiebos  ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2019/12/05 10:01:43 by melodiebos  ###    #+. /#+    ###.fr     */
>>>>>>> temp-branch
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

//-------------------------------------------------- A FAIRE
void 	*get_u(va_list params)
{
	unsigned int	*p_int;
	unsigned int 	var;

	var = va_arg(params, unsigned int);
    if (!(p_int = malloc(sizeof(unsigned int))))
		return (NULL);
    *p_int = var;
	return ((void *)p_int);
}
<<<<<<< HEAD
void 	*get_p(va_list params)
{
	char		*p_p = NULL;
	(void)params;
=======
>>>>>>> temp-branch

//--------------------------------------------------
