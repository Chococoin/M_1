/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:22:24 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 14:06:37 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_hex_digit(unsigned int d, char f)
{
	if (d < 10)
		return ('0' + (d));
	else if (f == 'X')
		return ('A' + (d - 10));
	else
		return ('a' + (d - 10));
}
