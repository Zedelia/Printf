/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodieb <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:37:06 by melodieb     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:05:21 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H
# include "ft_printf.h"
/*
** Flags functions
** init, free, use and modify t_flags
*/
t_bool	flag_init(t_flag **l_flag, char *flag, va_list params);
t_bool	flag_parser(t_flag *l_flag, char *flags, va_list params);
void	flag_free(t_flag **l_flag);
t_bool	flag_width(t_flag *l_flag, char *flags, va_list params);
t_bool	flag_preci(t_flag *l_flag, char *preci, va_list params);

#endif
