/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:46:23 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/02/13 21:11:04 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		count_char;

	va_start (args, f);
	count_char = 0;
	while (*f)
	{
		if (*f == '%')
		{
			if (f[1] == ' ' || f[1] == '\0')
				return (count_char + printf_error());
			if (ft_strchr(F_SPEC, f[1]) != NULL)
				count_char += f_selector(&args, f);
			else if (f[1] == '%')
				count_char += ft_putchar(*f);
			f += 2;
		}
		else
		{
			count_char += ft_putchar(*f);
			f++;
		}
	}
	va_end(args);
	return (count_char);
}
