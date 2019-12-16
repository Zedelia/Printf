/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 11:58:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 17:44:12 by mbos        ###    #+. /#+    ###.fr     */
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

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN	"\x1b[36m"
# define RESET	"\033[0;37m"

# define INDICATORS "cspdiuxX%"
# define FLAGS "-0.*"
# define STRING_NULL "(null)"

typedef unsigned long long	t_uintmax;
typedef unsigned char		t_uchar;

typedef enum
{
	False = 0,
	True = 1,
}	t_bool;

typedef enum
{
	_c = 0,
	_s,
	_p,
	_d,
	_i,
	_u,
	_x,
	_big_x,
	_percent,
	size
}	t_type_indicator;
/*
** Struct declarations
** -----> s_format 		 : use to save and modify the entire printf first param
** -----> s_input 	: use to identify and apply input like '%...s'
** -----> s_flag		 : use to identify flags
*/
typedef struct s_input	t_input;
typedef struct s_format	t_format;
typedef struct s_flag		t_flag;

struct		s_format
{
	char			*format;
	char			*new_format;
	size_t			full_len_newformat;
	t_input			*l_input;
};

struct		s_input
{
	char			*p_input;
	char			*input_cpy;
	char			*output;
	void			*varg;
	char			indicator;
	int				len;
	t_flag			*l_flag;
	t_input			*next;
};

struct		s_flag
{
	char	type;
	void	*preci;
	void	*width;
	t_bool	arg_neg;
};

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
int			ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
int			is_flags(char c);
t_bool		is_indicator(char c);
size_t		ft_index(char c, const char *charset);
char		*convert_base_int_to_hex(unsigned int var);
int			occur_before(char c, char *charset, char before);
int			occur_after(char c, char *charset, char after);
char		*create_malloc(char *cpy_output, int len);
char		*convert_base_int_to_unsigned(int temp);
char		*ft_utoa(unsigned int nbr);

#endif
