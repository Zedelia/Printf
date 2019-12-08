/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:01:16 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 19:54:44 by melodiebos  ###    #+. /#+    ###.fr     */
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



#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\033[0;37m"

#define INDICATORS "cspdiuxX\%"
#define FLAGS "-0.*"

typedef enum
{
	False = 0,
	True = 1,
}			t_bool;

/*
** Struct declarations
** -----> s_format 		 : use to save and modify the entire printf first param
** -----> s_pattern 	: use to identify and apply pattern like '%...s'
** -----> s_flag		 : use to identify flags
*/

typedef struct s_pattern t_pattern;
typedef struct s_format t_format;
typedef struct s_flag t_flag;

struct      s_format
{
	char*			format;
	char* 			new_format;
	t_pattern*		l_pattern;
};

struct      s_pattern
{
	char			*p_pattern;
	char			*pattern_cpy;
	char			*result;
	void		 	*varg;
	char			indicateur;
	int				len;
	t_flag			*l_flag;
	t_pattern		*next;
};

struct      s_flag
{
	char   			flag_type;
	void			*precision;
	void			*width;
};

/*
** Utils functions
**
*/
int 		ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
int			is_flags(char c);
t_bool		is_indicator(char c);
size_t		ft_index(char c, const char *charset);
char		*convert_base_int_to_hex(unsigned int var);
int			occurence_before(char c, char *charset, char before);
int			occurence_after(char c, char *charset, char after);
char 		*create_malloc(char *copy_result, int len);
char		*convert_base_int_to_unsigned(int temp);
char		*ft_utoa(unsigned int nbr);
/*
** Convert functions
**
*/
t_bool 	apply_flags_di(t_pattern *l_pattern);

t_bool		apply_di_arg_zero(t_pattern *l_pattern);
t_bool	apply_flag_di_zero_pos(t_pattern *l_pattern, char *cpy_result);
t_bool apply_flag_di_zero_neg(t_pattern *l_pattern, char *cpy_result);
// t_bool 	apply_flag_di_zero(t_pattern *l_pattern, char *copy_width);
t_bool 	apply_flag_di_tiret(char *copy_width, t_pattern *l_pattern);
t_bool	apply_flags_cs(t_pattern *l_pattern);
t_bool 	apply_flag_cs_tiret(t_pattern *l_pattern, char *copy_result);
t_bool 	apply_flag_cs_none(t_pattern *l_pattern, char *copy_result);
/*
** Format functions
** init, free, use and modify t_format
*/
t_bool	format_init(t_format **s_format, const char *format, va_list params);
void 	format_free(t_format **s_format);
t_bool	format_parser(t_format *s_format, char *format, va_list params);
void 	format_add_pattern(t_format *s_format, t_pattern *l_pattern);
t_bool	format_replace_pattern(t_format *s_format);
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
void 	pattern_add_flag(t_pattern *l_pattern, t_flag *l_flag);
t_bool	pattern_copy(t_pattern *l_pattern);
t_bool	pattern_check(t_pattern *l_pattern);
t_bool  pattern_convert(t_pattern *l_pattern);
/*
** Flags functions
** init, free, use and modify t_flags
*/
t_bool	flag_init(t_flag **l_flag, char *flag, va_list params);
t_bool 	flag_parser(t_flag *l_flag, char *flags, va_list params);
void 	flag_free(t_flag **l_flag);
t_bool	flag_width(t_flag *l_flag, char *flags, va_list params);
t_bool	flag_precision(t_flag *l_flag, char *precision, va_list params);
// void 	flag_free_one(t_flag **l_flag);


/*
** Get_functions
** cspdiuxX%
*/
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

void 				init_get_fct_tab(void);
typedef void		*(t_get_fct)(va_list);
t_get_fct			*g_get_fct[size];

t_bool				get_arg(t_pattern *l_pattern, va_list params);
void				*get_c(va_list params);
void 				*get_s(va_list params);
void	 			*get_p(va_list params);
void 				*get_di(va_list params);
void 				*get_x(va_list params);
void 				*get_percent(va_list params);

void 				init_convert_fct_tab(void);
typedef t_bool		(t_convert_fct)(t_pattern*);
t_convert_fct			*g_convert_fct[size];

t_bool	pattern_convert(t_pattern *l_pattern);
t_bool  convert_di(t_pattern *l_pattern);
t_bool  convert_s(t_pattern *l_pattern);
t_bool  convert_c(t_pattern *l_pattern);
t_bool  convert_p(t_pattern *l_pattern);
t_bool  convert_u(t_pattern *l_pattern);
t_bool  convert_x(t_pattern *l_pattern);
t_bool  convert_percent(t_pattern *l_pattern);


int 	*get_width_preci(char *width_or_preci);
t_bool 	get_indicator(t_pattern *l_pattern);

/*
** Error_functions pointers Tab
**
*/
typedef enum
{
	_several_flags = 0,
	_too_many_stars,
	_zero_sc,
	_precision_c,
	_digit_stars_before_flag,
	_digit_stars_together,
	errors_size
} 	t_type_error;

void 				init_error_fct_tab(void);
typedef t_bool		(t_get_error_fct)(t_pattern*);
t_get_error_fct		*g_get_error_fct[errors_size];

t_bool 	get_errors(t_pattern *l_pattern);
t_bool	error_several_flags(t_pattern *l_pattern);
t_bool	error_too_many_stars(t_pattern *l_pattern);
t_bool	error_zero_sc(t_pattern *l_pattern);
t_bool	error_precision_c(t_pattern *l_pattern);
t_bool	error_digit_stars_before_flag(t_pattern *l_pattern);
t_bool	error_digit_stars_together(t_pattern *l_pattern);

/*
** Tests functions
**
*/
t_bool 				false_ret(const char *namefunc);

void 				show_format(t_format *s_format);
void 				show_one_pattern(t_pattern *l_pattern);
void 				show_pattern(t_pattern *l_pattern);
void 				show_one_flag(t_flag *l_flag);
void 				show_flag(t_flag *l_flag);
void 				init_show_varg(void);

typedef void		(t_show_varg)(t_pattern*);
t_show_varg			*g_show_varg[size];

void				show_varg(t_pattern *l_pattern);
void				show_c(t_pattern *l_pattern);
void 				show_s(t_pattern *l_pattern);
void	 			show_p(t_pattern *l_pattern);
void 				show_di(t_pattern *l_pattern);
void 				show_u(t_pattern *l_pattern);
void 				show_x(t_pattern *l_pattern);
void 				show_percent(t_pattern *l_pattern);

#endif
