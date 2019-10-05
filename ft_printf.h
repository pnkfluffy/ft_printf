/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:54:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/04 19:11:10 by jfelty           ###   ########.fr       */
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
	struct s_format	*args;	
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
	char			pound;
}					t_flag;

int	ft_printf(const char *str, ...);

#endif