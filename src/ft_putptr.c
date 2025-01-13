/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:47:40 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 19:11:00 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ptr_length(unsigned long d)
{
	int	length;

	length = 0;
	while (d > 0)
	{
		d /= 16;
		length++;
	}
	return (length + 2);
}

static unsigned long	cal_current_power(int i)
{
	unsigned long	current_power;
	int				j;

	j = 0;
	current_power = 1;
	while (j < i)
	{
		current_power *= 16;
		j++;
	}
	return (current_power);
}

static void	dec_to_hex_cal_ptr(int len, unsigned long dec, char *hex, char f_s)
{
	int				i;
	unsigned long	current_power;
	unsigned long	digit;

	digit = dec;
	i = len - 1;
	while (i >= 0)
	{
		current_power = cal_current_power(i);
		digit = dec / current_power;
		dec -= digit * current_power;
		hex[i] = get_hex_digit(digit, f_s);
		i--;
	}
	hex[0] = '0';
	hex[1] = 'x';
	hex[len + 1] = '\0';
}

int	ft_putptr(void *ptr)
{
	int		len;
	char	*hex;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = ptr_length((unsigned long)ptr);
	hex = malloc(sizeof(char) * (len + 1));
	dec_to_hex_cal_ptr(len, (unsigned long)ptr, hex, 'x');
	ft_putstr(hex);
	free(hex);
	return (len);
}
