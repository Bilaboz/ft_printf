/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:51:50 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/08 22:16:43 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	get_flags(const char *s, t_flags *flags)
{
	int		i;
	char	*valid_flags;

	i = 0;
	valid_flags = "-0# +";
	while (s[i] && char_is_in_str(s[i], valid_flags))
	{
		if (s[i] == '-')
			flags->minus = 1;
		else if (s[i] == '0')
			flags->zero = 1;
		else if (s[i] == '#')
			flags->hashtag = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		i++;
	}
	return (i);
}

int	get_number(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (i)
		flags->number = ft_atoi(s);
	return (i);
}

int	get_dot(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		flags->dot = 1;
		while (s[i] && (s[i] >= '0' && s[i] <= '9'))
			i++;
		if (i > 1)
			flags->dot_nb = ft_atoi(s + 1);
	}
	if (flags->dot)
		flags->zero = 0;
	return (i);
}

int	get_type(const char *s, t_flags *flags)
{
	char	*valid_types;

	valid_types = "cspdiuxX%";
	if (char_is_in_str(*s, valid_types))
	{
		flags->type = *s;
		return (1);
	}
	return (0);
}

int	parse_flags(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	init_struct(flags);
	i += get_flags(s, flags);
	i += get_number(s + i, flags);
	i += get_dot(s + i, flags);
	i += get_type(s + i, flags);
	return (i);
}
