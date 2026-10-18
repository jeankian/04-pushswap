/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:31:01 by jkian             #+#    #+#             */
/*   Updated: 2026/09/26 16:40:58 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *a, ...);
void	ft_char(int *i, int *ct, va_list *ap);
void	ft_str(int *i, int *ct, va_list *ap);
void	ft_voidptr(int *i, int *ct, va_list *ap);
void	ft_dec_int(int *i, int *ct, va_list *ap);
void	ft_undec(int *i, int *ct, va_list *ap);
void	ft_hexlo(int *i, int *ct, va_list *ap);
void	ft_hexup(int *i, int *ct, va_list *ap);
void	ft_putchar(char c, int *ct);
void	ft_putstr(char *s, int *ct);

#endif
