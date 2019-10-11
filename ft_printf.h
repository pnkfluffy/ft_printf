/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:54:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/11 13:17:29 by jfelty           ###   ########.fr       */
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

t_print				*initialize(const char *str);
int					ft_printf(const char *str, ...);
void				print_params(t_format *curr);

/*
**	populate.c
*/

int					print_c(t_format *format, va_list args);
int					print_s(t_format *format, va_list args);
int					print_i(t_format *format, va_list args);

/*
**	populate.c
*/

int					populate_flags(t_format *curr, char *fmt);
void				initialize_values(t_format *curr);
void				populate_format(t_format *curr, char *fmt);
t_format			*fill_format(t_format *head, char *fmt);
int					get_format(char *str, char **fmt);

#endif