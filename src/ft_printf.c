/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:46:23 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/02/12 16:45:00 by glugo-mu         ###   ########.fr       */
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
		if (*f == '%' && ft_strchr(F_SPEC, f[1]) != NULL)
		{
			count_char += f_selector(&args, f);
			f += 2;
		}
		else if (*f == '%' && f[1] == '%')
		{
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
