/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:01:28 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/04 17:52:15 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_is_valid(char *str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	number;
	int			base_len;

	number = nbr;
	base_len = ft_strlen(base);
	if (base_len < 2 || !base_is_valid(base))
		return ;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number > (base_len - 1))
	{
		ft_putnbr_base(number / base_len, base);
		ft_putnbr_base(number % base_len, base);
	}
	else
		ft_putchar(base[number]);
}
