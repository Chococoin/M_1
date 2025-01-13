/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:47:40 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 14:20:47 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	char			*buffer;
	int				len;
	int				started;
	int				i;
	int				digit;

	len = 0;
	buffer = malloc(sizeof(void *) * 21);
	buffer[len++] = '0';
	buffer[len++] = 'x';
	addr = (unsigned long)ptr;
	started = 0;
	i = (sizeof(addr) * 2);
	while (i >= 0)
	{
		digit = (addr >> (i * 4)) & 0xF;
		if (digit != 0 || started)
		{
			buffer[len++] = get_hex_digit(digit, 'x');
			started = 1;
		}
		i--;
	}
	if (!started)
		buffer[len++] = '\0';
	buffer[len] = '\0';
	return (len);
}
