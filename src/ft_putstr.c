/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:55:28 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/13 21:03:42 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *c)
{
	int	len;

	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (*c != '\0')
	{
		ft_putchar(c);
		c++;
		len++;
	}
	return (len);
}
