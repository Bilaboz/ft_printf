/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:57:53 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 15:57:51 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	t_flags	flags;
	int		ret_val;

	i = 0;
	ret_val = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i += parse_flags(&format[i + 1], &flags);
			process_flags(&flags, ap);
		}
		else
			write_buf((char *)&format[i], 1);
		i++;
	}
	va_end(ap);
	ret_val = manage_buffer(NULL, 0);
	return (ret_val);
}
