/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:19:36 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 15:22:03 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_putnbr_hex(unsigned long value, char *base)
{
	unsigned char	low;
	char			result[17];
	int				i;

	result[16] = '\0';
	i = 15;
	if (!value)
		return (write_buf("0", 1));
	while (value > 0)
	{
		low = value & 0x0f;
		result[i] = base[low];
		value = value >> 4;
		i--;
	}
	write_buf(&result[i + 1], 15 - i);
}

void	init_struct(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->dot = 0;
	flags->dot_nb = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->number = 0;
	flags->type = 0;
}

int	char_is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_digits(int nb)
{
	int			digit_nb;
	long int	n;

	n = nb;
	digit_nb = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		digit_nb++;
	}
	return (digit_nb);
}

int	print_char(char c, int count)
{
	char	*res;
	int		i;

	i = 0;
	if (count <= 0)
		return (0);
	res = malloc(sizeof(char) * count + 1);
	if (!res)
		return (0);
	while (i < count)
	{
		res[i] = c;
		i++;
	}
	write_buf(res, count);
	free(res);
	return (count);
}
