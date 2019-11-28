/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:16 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 14:50:26 by mbos        ###    #+. /#+    ###.fr     */
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
** -----> s_pattern : use to identify and apply pattern like '%...s'
** -----> s_flag		 : use to identify and apply flags
*/

typedef struct s_pattern t_pattern;
typedef struct s_format t_format;
typedef struct s_flag t_flag;

struct      s_format
{
	char*				format;
	t_pattern*		l_pattern;
};

struct      s_pattern
{
	char			*pattern;
	char			*result;
// repasser en void*
	void		 	*varg;
	char			indicateur;
	int				len;
	t_flag			*l_flag;
	t_pattern		*next;
};

struct      s_flag
{
	char   			flag_type;
	int				precision;
	int				width;
	t_flag 			*next;
};


// ca je sais pas ou le mettre
int 	ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
int		ft_is_flags(char c);
int		ft_is_indicateur(char c);
size_t	ft_index(char c, const char *charset);
char	*convert_base_int_to_hex(unsigned int var);

/*
** Format functions
** init, free, use and modify t_format
*/

t_bool	format_init(t_format **s_format, const char *format, va_list params);
void 	format_free(t_format **s_format);
t_bool	format_parser(t_format *s_format, char *format, va_list params);
void 	format_add_pattern(t_format *s_format, t_pattern *l_pattern);
/*
** Pattern functions
** init, free, use and modify t_format
*/
t_bool	pattern_init(t_pattern **l_pattern, char *format, va_list params);
void 	pattern_free(t_pattern **l_pattern);
void 	pattern_free_one(t_pattern **l_pattern);
t_bool 	pattern_apply(char *format, t_pattern *conv);
t_bool 	pattern_parser(t_pattern *l_pattern, va_list params);
char	*convert_me(t_pattern *l_pattern);
/*
** Flags functions
** init, free, use and modify t_flags
*/
t_bool	flags_init(t_flag **l_flag, char *format, va_list params);
t_bool 	flag_parser(t_flag *l_flag, char *pflag);
/*
** Get_arg functions
** cspdiuxX%
*/
#define INDICATORS "cspdiuxX\%"

void init_get_fct_tab(void);

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
} t_type_indicateur;

typedef void		*(t_get_fct)(va_list);
t_get_fct			*g_get_fct[size];

t_bool		get_arg(t_pattern *l_pattern, va_list params);
void		*get_c(va_list params);
void 		*get_s(va_list params);
void	 	*get_p(va_list params);
void 		*get_di(va_list params);
void 		*get_u(va_list parans);
void 		*get_x(va_list params);
void 		*get_percent(va_list params);

/*
** Tests functions
**
*/
void 	show_format(t_format *s_format);
void 	show_one_pattern(t_pattern *l_pattern);
void 	show_pattern(t_pattern *l_pattern);

typedef void		*(t_show_varg)(char);
t_show_varg			*g_show_varg[size];

void		show_varg(char);
void		*show_c(va_list params);
void 		*show_s(va_list params);
void	 	*show_p(va_list params);
void 		*show_di(va_list params);
void 		*show_u(va_list parans);
void 		*show_x(va_list params);
void 		*show_percent(va_list params);

#endif
