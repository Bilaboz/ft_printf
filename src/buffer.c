/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:25:38 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/10 13:34:59 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	write_buf(char *s, size_t n)
{
	manage_buffer(s, n);
}

static void	flush_buffer(char *buffer, size_t *curr_buf_size)
{
	write(1, buffer, *curr_buf_size);
	buffer[0] = '\0';
	*curr_buf_size = 0;
}

static int	concat_buff(char *buff, size_t curr_buf_size, char *s, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < n && curr_buf_size + j < FT_PRINTF_BUFFER_SIZE)
	{
		buff[curr_buf_size + j] = s[j];
		j++;
	}
	buff[curr_buf_size + j] = '\0';
	return (j);
}

int	manage_buffer(char *s, size_t n)
{
	static char		buffer[FT_PRINTF_BUFFER_SIZE + 1];
	static size_t	curr_buf_size = 0;
	static int		char_count = 0;
	int				tmp;
	int				bytes_copied;

	if (!n && !s)
	{
		tmp = char_count;
		flush_buffer(buffer, &curr_buf_size);
		char_count = 0;
		return (tmp);
	}
	bytes_copied = concat_buff(buffer, curr_buf_size, s, n);
	curr_buf_size += bytes_copied;
	char_count += bytes_copied;
	if (n != n - bytes_copied)
	{
		flush_buffer(buffer, &curr_buf_size);
		manage_buffer(&s[bytes_copied], n - bytes_copied);
	}
	if (char_is_in_str('\n', buffer))
		flush_buffer(buffer, &curr_buf_size);
	return (0);
}
