/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:20:11 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 11:40:03 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"

/*
** Utils functions
*/
int			put_output(const char *format, t_format *s_format, int ret);
int			ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));

size_t		ft_index(char c, const char *charset);
int			is_flags(char c);
t_bool		is_indicator(char c);
int			occur_before(char c, char *charset, char before);
int			occur_after(char c, char *charset, char after);
char		*create_malloc(char *cpy_output, int len);
char		*ft_utoa(unsigned int nbr);

#endif
