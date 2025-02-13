/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:19:43 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/02/13 19:23:20 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnum(int num)
{
	int		len;
	char	*num_str;

	num_str = ft_itoa(num);
	if (!num_str)
		return (0);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	return (len);
}
