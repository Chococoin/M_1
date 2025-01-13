/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:25:18 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 18:55:44 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hex_length(int decimal)
{
	int				length;
	unsigned int	d;

	length = 0;
	d = decimal;
	while (d > 0)
	{
		d /= 16;
		length++;
	}
	if (length == 0)
		length++;
	return (length);
}

static int	cal_current_power(int i)
{
	int	current_power;
	int	j;

	current_power = 1;
	j = 0;
	while (j < i)
	{
		current_power *= 16;
		j++;
	}
	return (current_power);
}

static void	dec_to_hex_cal(int len, unsigned int decimal, char *hex, char f_s)
{
	int				i;
	int				current_power;
	unsigned int	digit;

	digit = decimal;
	i = len - 1;
	while (i >= 0)
	{
		current_power = cal_current_power(i);
		digit = decimal / current_power;
		decimal -= digit * current_power;
		hex[len - 1 - i] = get_hex_digit(digit, f_s);
		i--;
	}
}

int	dec_to_hex(int decimal, char f_s)
{
	int				len;
	char			*hex;

	len = hex_length(decimal);
	hex = malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	dec_to_hex_cal(len, decimal, hex, f_s);
	ft_putstr(hex);
	free(hex);
	return (len);
}
