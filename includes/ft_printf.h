/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarles <rcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:19:26 by rcarles           #+#    #+#             */
/*   Updated: 2021/12/10 16:27:25 by rcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef FT_PRINTF_BUFFER_SIZE
#  define FT_PRINTF_BUFFER_SIZE 5
# endif

int	ft_printf(const char *format, ...);

#endif