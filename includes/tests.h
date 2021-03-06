/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:30 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:22:32 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "ft_printf.h"

/*
** Tests functions
*/
t_bool				false_ret(const char *namefunc);

void				show_format(t_format *s_format);
void				show_one_input(t_input *l_input);
void				show_input(t_input *l_input);
void				show_one_flag(t_flag *l_flag);
void				show_flag(t_flag *l_flag);
void				init_show_varg(void);

typedef void		(t_show_varg)(t_input*);
t_show_varg			*g_show_varg[size];

void				show_varg(t_input *l_input);
void				show_c(t_input *l_input);
void				show_s(t_input *l_input);
void				show_p(t_input *l_input);
void				show_di(t_input *l_input);
void				show_u(t_input *l_input);
void				show_x(t_input *l_input);
void				show_percent(t_input *l_input);

#endif
