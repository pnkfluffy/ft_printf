/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:54:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/25 17:57:23 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./src/libft/libft.h"

//DELETE
#include <stdio.h>

# define CONV "cspdiouxXf%"
# define FLAG "-0+ #"
# define INTMIN -2147483648

typedef struct		s_print
{
	const char		*str;
	int				ret;
	struct s_format	*fmts;	
}					t_print;

typedef struct		s_format
{		
	char			*retstr;
	char			*fmt;
	char			type;
	int				has_width;
	int				has_precision;
	int				width;
	int				precision;
	int				lmod;
	struct s_flag	*flag;
	struct s_format	*next;
}					t_format;

typedef struct		s_flag
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				pound;
}					t_flag;

typedef int			jump_function(t_format *format, va_list args);

/*
**	ft_printf.c
*/

int					ft_printf(const char *str, ...);
t_print				*initialize(const char *str);

/*
**	format_help.c
*/

char				*join_padding(char *str, char *padding, int ljustify);
int64_t				get_arg_signed(int lmod, va_list args);
uint64_t			get_arg_unsigned(int lmod, va_list args);
int					has_lead(t_format *format, int64_t num);
char				*get_lead(t_format *format, int num);

/*
**	format_csp.c
*/

int					format_c(t_format *format, va_list args);
int					format_s(t_format *format, va_list args);
int					format_p(t_format *format, va_list args);

/*
**	format_diou.c
*/

int					format_di(t_format *format, va_list args);
int					format_o(t_format *format, va_list args);
int					format_u(t_format *format, va_list args);
int					format_xX(t_format *format, va_list args);


/*
**	populate.c
*/

int					populate_flags(t_format *curr, char *fmt);
void				initialize_values(t_format *curr);
void				populate_format(t_format *curr, char *fmt);
t_format			*fill_format(t_format *head, char *fmt);
int					get_format(char *str, char **fmt);

#endif