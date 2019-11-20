/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/18 18:55:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 15:32:42 by mbos        ###    #+. /#+    ###.fr     */
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
# include "../libft/includes/libft.h"

typedef enum
{
	False = 0,
	True = 1,
}		t_bool;

/*
** Strut declarations
** -----> s_format 		 : use to save and modify the entire printf first param
** -----> s_pattern_conv : use to identify and apply pattern like '%...s'
** -----> s_flag		 : use to identify and apply flags
*/

typedef struct s_pattern_conv t_pattern_conv;
typedef struct s_format t_format;
typedef struct s_flag t_flag;

struct      s_format
{
	char*             format;
	t_pattern_conv*     l_pattern_conv;
};

struct      s_pattern_conv
{
	char 			*pattern;
	char            indicateur;
	t_flag          *l_flag;
	int				len;
	char			*result;
	void			*varg;
	t_pattern_conv    *next;
};

struct      s_flag
{
	char   			type;
	int     		precision;
	t_flag 			*next;
};


// ca je sais pas ou le mettre
int ft_printf(char *s, ...) __attribute__((format(printf, 1, 2)));
t_bool	format_parser(char *format, va_list params);
t_bool 	apply_pattern_conv(char *format, t_pattern_conv *conv);

t_bool	init_format(t_format **self, char *format, va_list params);
t_bool	init_pattern_conv(t_pattern_conv **self, char *format, va_list params);
t_bool	init_flag(t_flag **self, char *format, va_list params);

t_bool 	pattern_conv_parser(char *format, va_list params);
t_bool 	flag_parser(t_flag *self, char *pflag);

char	*convert_me(t_pattern_conv *self);



#endif