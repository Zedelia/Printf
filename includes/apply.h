/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   apply.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:02 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 13:19:23 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef APPLY_H
# define APPLY_H
# include "ft_printf.h"
/*
** Convert functions
*/
t_bool	apply_diux(t_input *l_input);
t_bool	apply_diux_arg_zero(t_input *l_input);
t_bool	apply_diux_zero_pos(t_input *l_input, char *cpy_output);
t_bool	apply_diux_zero_neg(t_input *l_input, char *cpy_output);
t_bool	apply_diux_tiret(char *cpy_width, t_input *l_input);
t_bool	apply_cs(t_input *l_input);
t_bool	apply_cs_tiret(t_input *l_input);
t_bool	apply_cs_none(t_input *l_input);
t_bool	apply_diux_zero(t_input *l_input);
t_bool	apply_percent(t_input *l_input);
char 	*create_output_str_sc(t_input *l_input, char *cpy_output);

#endif
