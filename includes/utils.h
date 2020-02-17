/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:43 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:22:43 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"

/*
** Utils functions
*/
size_t		ft_index(char c, const char *charset);
int			is_flags(char c);
t_bool		is_indicator(char c);
int			occur_before(char c, char *charset, char before);
int			occur_after(char c, char *charset, char after);
char		*create_malloc(char *cpy_output, int len);
char		*ft_utoa(unsigned int nbr);

#endif
