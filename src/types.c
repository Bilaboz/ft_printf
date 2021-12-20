/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:52:30 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 16:02:24 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	handle_char(char c, t_flags *flags)
{
	if (flags->number && !flags->minus)
		print_char(' ', flags->number - 1);
	write_buf(&c, 1);
	if (flags->minus)
		print_char(' ', flags->number - 1);
}

void	handle_unsigned(unsigned int nb, t_flags *flags)
{
	int	digits;
	int	temp;

	temp = flags->dot_nb;
	digits = count_digits_unsigned_base(nb, 10);
	if (!nb && flags->dot && !flags->dot_nb)
		digits = 0;
	if (flags->dot_nb < digits)
		flags->dot_nb = digits;
	if ((flags->number && !flags->minus && !flags->zero)
		|| (flags->zero && flags->dot))
		print_char(' ', flags->number - flags->dot_nb);
	if (flags->zero && !flags->dot)
		print_char('0', flags->number - digits);
	if (flags->dot)
		print_char('0', flags->dot_nb - digits);
	if (!flags->dot || temp || nb)
		ft_putnbr_unsigned(nb);
	if (flags->minus)
		print_char(' ', flags->number - flags->dot_nb);
}

void	handle_int(int nb, t_flags *flags)
{
	int	digits;
	int	prefix;
	int	temp;

	prefix = 0;
	temp = flags->dot_nb;
	digits = count_digits(nb);
	if (!nb && flags->dot && !flags->dot_nb)
		digits = 0;
	if ((nb >= 0 && (flags->plus || flags->space)) || (nb < 0 && flags->number))
		prefix++;
	if (flags->dot_nb < digits)
		flags->dot_nb = digits;
	if (flags->number && !flags->minus && !flags->zero)
		print_char(' ', flags->number - flags->dot_nb - prefix);
	nb = process_prefix(flags, nb);
	if (flags->zero && !flags->dot)
		print_char('0', flags->number - digits - prefix);
	if (flags->dot)
		print_char('0', flags->dot_nb - digits);
	if (!flags->dot || temp || nb)
		ft_putnbr_buff(nb);
	if (flags->minus)
		print_char(' ', flags->number - flags->dot_nb - prefix);
}

void	handle_ptr(void *ptr, t_flags *flags)
{
	unsigned long	value;
	int				digits_nb;

	value = (unsigned long) ptr;
	digits_nb = count_digits_unsigned_base(value, 16) + 2;
	if (!ptr)
		digits_nb = 3;
	if (!flags->minus && flags->number)
		print_char(' ', flags->number - digits_nb);
	if (!ptr)
		return (write_buf("0x0", 3));
	write_buf("0x", 2);
	ft_putnbr_hex(value, "0123456789abcdef");
	if (flags->minus)
		print_char(' ', flags->number - digits_nb);
}

void	handle_hex(unsigned int nb, t_flags *flags, char *base)
{
	int	digits;
	int	hashtag;
	int	temp;

	temp = flags->dot_nb;
	digits = count_digits_unsigned_base(nb, 16);
	if (!nb && flags->dot && !flags->dot_nb)
		digits = 0;
	hashtag = process_hashtag(flags, nb, 0);
	if (flags->dot_nb < digits)
		flags->dot_nb = digits;
	if ((flags->number && !flags->minus && !flags->zero)
		|| (flags->zero && flags->dot))
		print_char(' ', flags->number - flags->dot_nb - hashtag);
	process_hashtag(flags, nb, 1);
	if (flags->zero && !flags->dot)
		print_char('0', flags->number - digits - hashtag);
	if (flags->dot)
		print_char('0', flags->dot_nb - digits);
	if (!flags->dot || temp || nb)
		ft_putnbr_hex(nb, base);
	if (flags->minus)
		print_char(' ', flags->number - flags->dot_nb - hashtag);
}
