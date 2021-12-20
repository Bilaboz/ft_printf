/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:32:00 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/13 15:31:01 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		space;
	int		dot;
	int		dot_nb;
	int		hashtag;
	int		plus;
	int		number;
	char	type;
}	t_flags;

/* buffer.c */

void	write_buf(char *s, size_t n);
int		manage_buffer(char *s, size_t n);

/* utils.c && utils2.c */

int		count_digits(int nb);
void	ft_putnbr_buff(int nb);
void	init_struct(t_flags *flags);
int		print_char(char c, int count);
int		char_is_in_str(char c, char *str);
void	ft_putnbr_unsigned(unsigned int nb);
void	ft_putnbr_hex(unsigned long value, char *base);
int		count_digits_unsigned_base(unsigned long n, int base_len);

/* types.c && types2.c */

void	handle_percent(t_flags *flags);
void	handle_int(int nb, t_flags *flags);
void	handle_char(char c, t_flags *flags);
void	handle_ptr(void *ptr, t_flags *flags);
void	handle_str(const char *s, t_flags *flags);
void	handle_unsigned(unsigned int nb, t_flags *flags);
void	handle_hex(unsigned int nb, t_flags *flags, char *base);

/* process_flags.c */

int		process_prefix(t_flags *flags, int nb);
void	process_flags(t_flags *flags, va_list ap);
int		parse_flags(const char *s, t_flags *flags);
int		process_hashtag(t_flags *flags, unsigned int nb, int print);

#endif