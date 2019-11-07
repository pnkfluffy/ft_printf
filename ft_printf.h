/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:54:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 21:31:59 by jfelty           ###   ########.fr       */
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
# define LONGMIN -9223372036854775808

typedef struct		s_print
{
	char			*str;
	int				ret;
	struct s_format	*fmts;	
}					t_print;

typedef struct		s_format
{		
	char			*retstr;
	char			*fmt;
	char			type;
	int				has_width;
	int				has_prec;
	int				width;
	int				prec;
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

void				initialize(t_print *print, const char *str);
int					print_char(t_format *format);
int					print_out(t_print *print);
int					ft_printf(const char *str, ...);

/*
**	format_help.c
*/

char				*join_pad(char *str, char *padding, int ljustify);
int64_t				get_arg_signed(int lmod, va_list args);
uint64_t			get_arg_unsigned(int lmod, va_list args);
int					has_lead(t_format *format, int64_t num);
char				*get_lead(t_format *format, int64_t num);

/*
**	format_help2.c
*/

char				get_pad(t_format *format, char *ret);
int					null_check(t_format *format);
int					get_format(char *str, char **fmt);
void				free_strings(char **str1, char **str2, char **str3);
int					fmt_di_help(t_format *fmt, int64_t num, char **ret);

/*
**	format_cspf.c
*/

int					format_c(t_format *format, va_list args);
int					format_s(t_format *format, va_list args);
int					format_p(t_format *format, va_list args);
char				*get_decimal(long double num, int precision);
int					format_f(t_format *format, va_list args);

/*
**	format_diouxX.c
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
int					populate_lenmod(t_format *curr, char *fmt);
void				populate_format(t_format *curr, char *fmt);
t_format			*fill_format(t_format *head, char *fmt);

/*
**	dispatch.c
*/

int					get_choice(t_format *format);
int					dispatch(t_print *print, va_list args);

#endif