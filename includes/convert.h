/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:09 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 15:02:02 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "ft_printf.h"

void				init_convert_fct_tab(void);
typedef t_bool		(t_convert_fct)(t_input*);
t_convert_fct		*g_convert_fct[size];

t_bool	input_convert(t_input *l_input);
t_bool	convert_di(t_input *l_input);
t_bool	convert_s(t_input *l_input);
t_bool	convert_c(t_input *l_input);
t_bool	convert_p(t_input *l_input);
t_bool	convert_u(t_input *l_input);
t_bool	convert_x(t_input *l_input);
t_bool	convert_percent(t_input *l_input);

#endif
