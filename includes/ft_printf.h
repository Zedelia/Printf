/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 16:19:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>

# include "../libft/includes/libft.h"
# include "styles.h"
# include "typedef.h"

# include "inputs.h"
# include "apply.h"
# include "convert.h"
# include "errors.h"
# include "flags.h"
# include "format.h"
# include "get.h"
# include "tests.h"

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
