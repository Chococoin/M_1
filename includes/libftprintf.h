/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:52:50 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/08 22:32:30 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include "libft.h"
# define F_SPEC "csdixXpu"

int	f_selector(va_list *args, const char *format);
int	ft_putchar(const char *s);
int	ft_putstr(char *c);
int	ft_printf(const char *format, ...);
int ft_putnum(int num);
int ft_putptr(void *ptr);
int	get_hex_digit(int digit, char f);
int	dec_to_hex(int decimal, char f);

#endif