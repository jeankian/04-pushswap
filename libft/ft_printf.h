/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:38:23 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/10 13:42:29 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_specifier(char specifier, va_list ap, int count);
int	print_char(int c);
int	print_str(char *str);
int	print_int(int nb);
int	print_unsigned(unsigned int nb, char specifier);
int	print_pointer(void *ptr);

#endif