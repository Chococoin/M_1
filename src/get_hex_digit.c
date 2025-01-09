/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:22:24 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/09 17:26:04 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libftprintf.h"

int	get_hex_digit(int digit, char f)
{
	if (digit < 10)
		return ('0' + digit);
	else if (f == 'X')
		return ('A' + (digit - 10));
	else
		return ('a' + (digit - 10));
}
