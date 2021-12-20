/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:56:45 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 15:35:02 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_putnbr_buff(int nb)
{
	char		c;
	long int	n;

	n = (long int) nb;
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		ft_putnbr_buff(n / 10);
		ft_putnbr_buff(n % 10);
	}
	else
	{
		c = n + '0';
		write_buf(&c, 1);
	}
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	char			c;
	unsigned long	n;

	n = (unsigned long) nb;
	if (n < 0)
	{
		n *= -1;
		write_buf("-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_buff(n / 10);
		ft_putnbr_buff(n % 10);
	}
	else
	{
		c = n + '0';
		write_buf(&c, 1);
	}
}

int	count_digits_unsigned_base(unsigned long n, int base_len)
{
	int	digit_nb;

	digit_nb = 1;
	while (n >= (unsigned long) base_len)
	{
		n /= base_len;
		digit_nb++;
	}
	return (digit_nb);
}
