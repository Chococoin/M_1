/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:41:59 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/09 15:42:20 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int put_unsigned_num(unsigned int num)
{
	int 			len;
	unsigned int 	n;

	n = num;
	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	write(1, ft_uitoa(num), len);
	return (len);
}
