/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:02:08 by jfelty            #+#    #+#             */
/*   Updated: 2019/10/13 17:45:46 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*join_padding(char *str, char *padding, int ljustify)
{
	char	*ret;

	if (ljustify)
		ret = ft_strjoin(str, padding);
	else
		ret = ft_strjoin(padding, str);
	return (ret);
}

int64_t		get_arg_signed(int lmod, va_list args)
{
	int64_t	num;

	num = 0;
	if (lmod == 0)
		num = va_arg(args, int32_t);
	else if (lmod == 1)
		num = (int8_t)va_arg(args, int);
	else if (lmod == 2)
		num = (int16_t)va_arg(args, int);
	else if (lmod == 3 || lmod == 4)
		num = va_arg(args, int64_t);
	return (num);
}

uint64_t		get_arg_unsigned(int lmod, va_list args)
{
	uint64_t	num;

	num = 0;
	if (lmod == 0)
		num = va_arg(args, uint32_t);
	else if (lmod == 1)
		num = (uint8_t)va_arg(args, uint32_t);
	else if (lmod == 2)
		num = (uint16_t)va_arg(args, uint32_t);
	else if (lmod == 3 || lmod == 4)
		num = va_arg(args, uint64_t);
	return (num);
}