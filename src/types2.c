/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:26:46 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 16:01:07 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/* Because of 25 lines per function limit */
static void	handle_str2(t_flags *flags, char *copy, size_t len)
{
	if (flags->number && !flags->minus)
		print_char(' ', flags->number - len);
	write_buf(copy, len);
	if (flags->minus)
		print_char(' ', flags->number - len);
}

void	handle_str(const char *s, t_flags *flags)
{
	size_t	len;
	char	*copy;

	if (!s)
		copy = ft_strdup("(null)");
	else
		copy = ft_strdup(s);
	if (!copy)
		return ;
	if (flags->dot)
	{
		if (flags->dot_nb <= (int) ft_strlen(copy))
			copy[flags->dot_nb] = '\0';
		else if (!flags->dot_nb)
			copy[0] = '\0';
	}
	len = ft_strlen(copy);
	handle_str2(flags, copy, len);
	free(copy);
}

void	handle_percent(t_flags *flags)
{
	if (flags->dot_nb < 1)
		flags->dot_nb = 1;
	if (flags->number && !flags->minus && !flags->zero)
		print_char(' ', flags->number - flags->dot_nb);
	if (flags->zero && !flags->dot && !flags->minus)
		print_char('0', flags->number - 1);
	if (flags->dot)
		print_char('0', flags->dot_nb - 1);
	write_buf("%", 1);
	if (flags->minus)
		print_char(' ', flags->number - 1);
}
