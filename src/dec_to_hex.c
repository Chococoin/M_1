/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:25:18 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/08 22:22:16 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int hex_length(int decimal)
{
	int	length;

	length = 0;
	while (decimal > 0)
	{
		decimal /= 16;
		length++;
	}
	return (length);
}

static int	cal_current_power(int i)
{
	int	current_power;
	int j;

	current_power = 1;
	j = 0;
	while ( j < i)
	{
		current_power *= 16;
		j++;
	}
	return (current_power);
}

int	dec_to_hex(int decimal, char f)
{
	int				len;
	char			*hexadecimal;
	int				i;
	int				current_power;
	unsigned int	digit;

	len = hex_length(decimal);
	hexadecimal = malloc(sizeof(char) * (len + 1));
	hexadecimal[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		current_power = cal_current_power(i);
		digit = decimal / current_power;
		decimal -= digit * current_power;
		hexadecimal[len - 1 - i] = get_hex_digit(digit, f);
		i--;
	}
	ft_putstr(hexadecimal);
	free(hexadecimal);
	return (len);
}
