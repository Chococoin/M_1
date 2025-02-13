/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_selector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:26:32 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/02/13 21:13:38 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	f_selector(va_list *args, const char *format)
{
	if (format[1] == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format[1] == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format[1] == 'd' || format[1] == 'i')
		return (ft_putnum(va_arg(*args, int)));
	else if (format[1] == 'x' || format[1] == 'X')
		return (dec_to_hex(va_arg(*args, int), format[1]));
	else if (format[1] == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (format[1] == 'u')
		return (put_unsigned_num(va_arg(*args, unsigned long)));
	return (0);
}
