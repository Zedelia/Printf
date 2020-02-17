/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:05 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:22:06 by mbos             ###   ########lyon.fr   */
/*                                                                            */
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
# include "flags.h"
# include "format.h"
# include "get.h"
# include "tests.h"
# include "utils.h"

int				put_output(const char *format, t_format *s_format, int ret);
int				ft_printf(const char *str,
		...) __attribute__((format(printf,1,2)));

#endif
