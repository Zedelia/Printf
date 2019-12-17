/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 16:21:17 by mbos        ###    #+. /#+    ###.fr     */
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
# include "utils.c"

#endif
