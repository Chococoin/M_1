/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:41:59 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/02/12 15:40:51 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_unsigned_num(unsigned int num)
{
	int		len;
	char	*num_str;

	num_str = ft_uitoa(num);
	if (!num_str)
		return (0);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	return (len);
}
