/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_selector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:26:32 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/08 19:36:27 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	f_selector(va_list *args, const char *format)
{
	char	*s;

	if (format[1] == 'c')
	{
		s = malloc(sizeof(int));
		s[0] = (char)va_arg(*args, int);
		return (ft_putchar(&s[0]));
	}
	else if (format[1] == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format[1] == 'd' || format[1] == 'i')
		return (ft_putnum(va_arg(*args, int)));
	else if (format[1] == 'x' || format[1] == 'X')
		return (dec_to_hex(va_arg(*args, int), format[1]));
	else if (format[1] == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (format[1] == 'u')
		return (1);
	else
		s = NULL;
	free(s);
	return (0);
}
