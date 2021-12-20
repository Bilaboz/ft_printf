/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:19:06 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 15:31:37 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	process_prefix(t_flags *flags, int nb)
{
	if (nb >= 0)
	{
		if (flags->plus)
			write_buf("+", 1);
		else if (flags->space)
			write_buf(" ", 1);
	}
	else
	{
		nb *= -1;
		write_buf("-", 1);
	}
	return (nb);
}

int	process_hashtag(t_flags *flags, unsigned int nb, int print)
{
	if (flags->hashtag && nb != 0)
	{
		if (print)
		{
			if (flags->type == 'X')
				write_buf("0X", 2);
			else if (flags->type == 'x')
				write_buf("0x", 2);
		}
		return (2);
	}
	return (0);
}

void	process_flags(t_flags *flags, va_list ap)
{
	if (flags->type == 'c')
		handle_char(va_arg(ap, int), flags);
	else if (flags->type == 's')
		handle_str(va_arg(ap, const char *), flags);
	else if (flags->type == 'p')
		handle_ptr(va_arg(ap, void *), flags);
	else if (flags->type == 'd' || flags->type == 'i')
		handle_int(va_arg(ap, int), flags);
	else if (flags->type == 'u')
		handle_unsigned(va_arg(ap, unsigned int), flags);
	else if (flags->type == 'x')
		handle_hex(va_arg(ap, unsigned int), flags, "0123456789abcdef");
	else if (flags->type == 'X')
		handle_hex(va_arg(ap, unsigned int), flags, "0123456789ABCDEF");
	else if (flags->type == '%')
		handle_percent(flags);
}
