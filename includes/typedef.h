/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:36 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:22:38 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "ft_printf.h"

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
typedef struct s_flag	t_flag;

struct		s_format
{
	char			*format;
	char			*pointer_f;
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
	t_bool	arg_weird;
};

#endif
