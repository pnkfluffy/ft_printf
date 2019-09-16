/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:54:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/09/15 18:05:17 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./src/libft/libft.h"

typedef struct		s_format
{
	char			*arg;
	char			type;
	int				left;
	int				zero;
	int				plus;
	int				blank;
	int				has_width;
	int				has_precision;
	int				width;
	int				precision;
	struct s_format	*next;	
}					t_format;

int	ft_printf(const char *str, char c, int i);

#endif