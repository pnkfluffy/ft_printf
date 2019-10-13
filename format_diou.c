/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_diou.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:55:53 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/12 19:08:12 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_d(t_format *format, va_list args)
{
	int64_t	num;
	char	*ret;

	num = get_arg_signed(format->lmod, args);



	return (0);
}
