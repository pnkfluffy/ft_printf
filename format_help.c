/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:02:08 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/06 21:56:30 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*join_pad(char *str, char *pad, int ljustify)
{
	char	*ret;

	if (ljustify)
		ret = ft_strjoin(str, pad);
	else
		ret = ft_strjoin(pad, str);
	return (ret);
}

int64_t			get_arg_signed(int lmod, va_list args)
{
	int64_t	num;

	num = 0;
	if (lmod == 0)
		num = (int)va_arg(args, int);
	else if (lmod == 1)
		num = (int8_t)va_arg(args, int);
	else if (lmod == 2)
		num = (int16_t)va_arg(args, int);
	else if (lmod == 3 || lmod == 4)
		num = (int64_t)va_arg(args, int64_t);
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

int				has_lead(t_format *fmt, int64_t num)
{
	if (fmt->flag->pound)
	{
		if (fmt->type == 'o')
			return (1);
		else if ((fmt->type == 'x' || fmt->type == 'X') && num != 0)
			return (2);
		return (0);
	}
	else if (fmt->flag->plus || fmt->flag->space)
		return (1);
	else if (ft_isneg(num) && (fmt->type == 'i' || fmt->type == 'd' \
	|| fmt->type == 'f'))
		return (1);
	return (0);
}

char			*get_lead(t_format *fmt, int64_t num)
{
	if (fmt->flag->pound)
	{
		if (fmt->type == 'o' && !(num == 0 && !fmt->has_prec))
			return ("0");
		else if (fmt->type == 'x' && num != 0)
			return ("0x");
		else if (fmt->type == 'X' && num != 0)
			return ("0X");
		return ("");
	}
	else if (fmt->flag->plus)
		return (ft_isneg(num) ? "-" : "+");
	else if (ft_isneg(num))
		return ("-");
	else if (fmt->flag->space)
		return (" ");
	return ("");
}
